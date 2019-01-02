import os
import torch
import torch.nn as nn
import torch.nn.functional as F
from torch.autograd import Variable
from torchsummary import summary


class SSD(nn.Module):
    def __init__(self, phase, base, extras, head, num_classes):
        super(SSD, self).__init__()
        self.phase = phase
        self.num_classes = num_classes
        self.priorbox = PriorBox(v2)  # default boxes size 8732x4, #  里面的 w,h 也归一化到0-1之间了吗?
        self.priors = Variable(self.priorbox.forward(), volatile=True)
        self.size = 300

        # SSD network
        self.vgg = nn.ModuleList(base)
        # Layer learns to scale the l2 normalized features from conv4_3
        self.L2Norm = L2Norm(512, 20)
        self.extras = nn.ModuleList(extras)

        self.loc = nn.ModuleList(head[0])
        self.conf = nn.ModuleList(head[1])

        if phase == 'test':
            self.softmax = nn.Softmax(dim=-1)
            self.detect = Detect(num_classes, 0, 200, 0.01, 0.45)

    def forward(self, x):
        """
        Return:
            test:
                Variable(tensor) of output class label predictions,
                confidence score, and corresponding location predictions for
                each object detected. Shape: [batch,topk,7]
            train:
                list of concat outputs from:
                    1: confidence layers, Shape: [batch*num_priors,num_classes]
                    2: localization layers, Shape: [batch,num_priors*4]
                    3: priorbox layers, Shape: [2,num_priors*4]
        """
        sources = list()  # 将6层的multibox层的输出暂存在这里
        loc = list()
        conf = list()

        # apply vgg up to conv4_3 relu
        for k in range(23):
            x = self.vgg[k](x)

        s = self.L2Norm(x)
        sources.append(s)

        # apply vgg up to fc7
        for k in range(23, len(self.vgg)):
            x = self.vgg[k](x)
        sources.append(x)

        # apply extra layers and 暂存 source layer outputs
        for k, v in enumerate(self.extras):
            x = F.relu(v(x), inplace=True)
            if k % 2 == 1:
                sources.append(x)

        # apply multibox head to source layers
        for (x, l, c) in zip(sources, self.loc, self.conf):
            loc.append(l(x).permute(0, 2, 3, 1).contiguous())
            conf.append(c(x).permute(0, 2, 3, 1).contiguous())

        loc = torch.cat([o.view(o.size(0), -1) for o in loc], 1)
        conf = torch.cat([o.view(o.size(0), -1) for o in conf], 1)
        if self.phase == "test":
            output = self.detect(
                loc.view(loc.size(0), -1, 4),                   # loc preds
                self.softmax(conf.view(conf.size(0), -1,
                    self.num_classes)),                         # conf preds
                self.priors.type(type(x.data))                  # default boxes
            )
        else:
            output = (
                loc.view(loc.size(0), -1, 4),
                conf.view(conf.size(0), -1, self.num_classes),
                self.priors
            )
        return output

    def load_weights(self, base_file):
        other, ext = os.path.splitext(base_file)
        if ext == '.pkl' or '.pth':
            print('Loading weights into state dict...')
            self.load_state_dict(torch.load(base_file,
                                 map_location=lambda storage, loc: storage))
            print('Finished!')
        else:
            print('Sorry only .pth and .pkl files supported.')


def vgg(base, batch_norm=False):
    """
    https://github.com/pytorch/vision/blob/master/torchvision/models/vgg.py
    """
    layers = []
    in_channels = 3
    for v in base:
        if v == 'M':
            layers += [nn.MaxPool2d(kernel_size=2, stride=2)]
        elif v == 'C':
            layers += [nn.MaxPool2d(kernel_size=2, stride=2, ceil_mode=True)]  # 向上取整
        else:
            conv2d = nn.Conv2d(in_channels, v, kernel_size=3, padding=1)
            if batch_norm:
                layers += [conv2d, nn.BatchNorm2d(v), nn.ReLU(inplace=True)]
            else:
                layers += [conv2d, nn.ReLU(inplace=True)]
            in_channels = v
    # add to the original vgg.
    pool5 = nn.MaxPool2d(kernel_size=3, stride=1, padding=1)  # 修改，去掉了origin中的2*2,s=2的pooling
    conv6 = nn.Conv2d(512, 1024, kernel_size=3, padding=6, dilation=6)
    conv7 = nn.Conv2d(1024, 1024, kernel_size=1)
    layers += [pool5, conv6, nn.ReLU(inplace=True), conv7, nn.ReLU(inplace=True)]
    return layers


def add_extras(extras):
    """
    Extra layers added to VGG for feature scaling 和论文中的结构一样
    """
    layers = []
    flag = False
    in_channels = 1024
    for k, v in enumerate(extras):
        if in_channels != 'S':
            if v == 'S':
                layers += [nn.Conv2d(in_channels, extras[k + 1],
                           kernel_size=(1, 3)[flag], stride=2, padding=1)]  # 有一次是向下取整5.5->5
            else:
                layers += [nn.Conv2d(in_channels, v, kernel_size=(1, 3)[flag])]
            flag = not flag
        in_channels = v
    return layers


def multibox(vgg, extra_layers, mbox, num_classes):  # [4, 6, 6, 6, 4, 4], 21
    loc_layers = []
    conf_layers = []
    vgg_source = [21, -2]
    for k, v in enumerate(vgg_source):  # (0,21),(1,-2)
        loc_layers += [nn.Conv2d(vgg[v].out_channels,
                                 mbox[k] * 4, kernel_size=3, padding=1)]
        conf_layers += [nn.Conv2d(vgg[v].out_channels,
                                  mbox[k] * num_classes, kernel_size=3, padding=1)]
    for k, v in enumerate(extra_layers[1::2], 2):  # start=2
        loc_layers += [nn.Conv2d(v.out_channels, mbox[k]* 4,
                                 kernel_size=3, padding=1)]
        conf_layers += [nn.Conv2d(v.out_channels, mbox[k]*num_classes,
                                  kernel_size=3, padding=1)]
    return vgg, extra_layers, (loc_layers, conf_layers)


base = [64, 64, 'M', 128, 128, 'M', 256, 256, 256, 'C', 512, 512, 512, 'M', 512, 512, 512]  # ,'M'
extras = [256, 'S', 512, 128, 'S', 256, 128, 256, 128, 256]
mbox = [4, 6, 6, 6, 4, 4]


def build_ssd(num_classes=21):
    base_, extras_, head_ = multibox(vgg(base), add_extras(extras), mbox, num_classes)
    return SSD(base_, extras_, head_)


def test_net():
    # x = torch.randn(16, 3, 300, 300)
    base_, extras_, head_ = build_ssd()
    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
    vgg_net = nn.Sequential(*extras_).to(device)
    summary(vgg_net, (1024, 19, 19))


if __name__ == '__main__':
    test_net()