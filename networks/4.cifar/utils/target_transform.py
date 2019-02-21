import numpy as np
import torch
from random import choice
import math


def target_transform(pkl, train, target):
    if train:
        return pkl[:5], target  # +torch.normal(0, std=torch.ones(5, 300)*0.1)
    else:
        return pkl[5:], target-5  # + torch.normal(0, std=torch.ones(5, 300) * 0.1)


def weights_init(m):
    classname = m.__class__.__name__
    if classname.find('Conv') != -1:
        try:
            n = m.kernel_size[0] * m.kernel_size[1] * m.out_channels
        except:
            n = m.kernel_size[0] * m.out_channels
        m.weight.data.normal_(0, math.sqrt(2. / n))
        if m.bias is not None:
            m.bias.data.zero_()
    elif classname.find('BatchNorm') != -1:
        m.weight.data.fill_(1)
        m.bias.data.zero_()
    elif classname.find('Linear') != -1:
        n = m.weight.size(1)
        m.weight.data.normal_(0, 0.01)
        m.bias.data = torch.ones(m.bias.data.size())

