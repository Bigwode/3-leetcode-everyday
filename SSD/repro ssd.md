### REPRO SSD

1、查看每一层feature map输出尺寸大小

```bash
pip install torchsummary
import torch
from torchvision import models
from torchsummary import summary

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
vgg = models.vgg16().to(device)

summary(vgg, (3, 224, 224))
```

2、注意base_network对vgg16的改变，去掉了最后一层2*2，strides=2的max pooling，改为3\*3，strides=1的pooling。为保证感受野相同，使用了空洞卷积。
$$
H_{out} = \left\lfloor\frac{H_{in}  + 2 \times \text{padding}[0] - \text{dilation}[0]
                        \times (\text{kernel_size}[0] - 1) - 1}{\text{stride}[0]} + 1\right\rfloor
$$
3、nn.ModuleList 和 nn.Sequential.的区别

nn.Sequential()有forward方法，而ModuleList没有。