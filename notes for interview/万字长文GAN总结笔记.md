# 万字综述之生成对抗网络（GAN）学习笔记

## 1、基本概念

![img](https://image.jiqizhixin.com/uploads/editor/de021a66-2e32-4530-a74c-69f802d8ed6d/640.png)

如图，隐变量 z （通常为服从高斯分布的随机噪声）通过 Generator 生成 Xfake, 判别器负责判别输入的 data 是生成的样本 Xfake 还是真实样本 Xreal。优化的目标函数如下：

![img](https://image.jiqizhixin.com/uploads/editor/5025bbd0-a23e-43ce-946e-4a0a638bd4ad/640.png)

对于判别器 D 来说，这是一个二分类问题，V(D,G) 为二分类问题中常见的交叉熵损失。

实际训练时，生成器和判别器采取交替训练，即先训练 D，然后训练 G，不断往复。

## 2、目标函数

原始GAN的问题：

-  判别器越好，生成器梯度消失越严重
- 最小化第二种生成器loss函数，会等价于最小化一个不合理的距离衡量，导致两个问题，一是梯度不稳定，二是collapse mode即多样性不足。

GAN 的目标函数是最小化两个分布的 **JS 散度**。实际上，衡量两个分布距离的方式有很多种，JS 散度只是其中一种。如果我们定义不同的**距离度量方式**，就可以得到不同的目标函数。许多对 GAN 训练稳定性的改进，比如 EBGAN，LSGAN 等都是定义了不同的分布之间距离度量方式。

例如，WGAN 提出了一种全新的距离度量方式——地球移动距离（EM, Earth-mover distance），也叫 Wasserstein 距离[3]，可以避免梯度突变问题。

![img](https://image.jiqizhixin.com/uploads/editor/6016d402-1354-4cd8-9ff4-7e0b81a9c6c3/640.png)

- 判别器最后一层去掉 sigmoid 
- 生成器和判别器的 loss 不取 log 
- 每次更新判别器的参数之后把它们的绝对值截断到不超过一个固定常数 c 
- 不要用基于动量的优化算法（包括momentum和Adam），推荐RMSProp，SGD也行

## ３、GAN常见的模型结构

**(1) DCGAN **

DCGAN 提出使用 CNN 结构来稳定 GAN 的训练，并使用了以下一些 trick： 

- Batch Normalization 
- 使用 Transpose convlution 进行上采样 
- 使用 Leaky ReLu 作为激活函数 

**(2) 层级结构**

GAN 对于高分辨率图像生成一直存在许多问题，层级结构的 GAN 通过逐层次，分阶段生成，一步步提生图像的分辨率。

## ４、GAN的训练障碍

- 在判别器达到最优的时候，等价于最小化生成分布与真实分布之间的 JS 散度，由于随机生成分布很难与真实分布有不可忽略的重叠以及 JS 散度的突变特性，使得生成器面临梯度消失的问题。
- ​

## 参考文献：

[1]、https://arxiv.org/abs/1711.05914

[2]、https://www.jiqizhixin.com/articles/2019-03-19-12

[3]、https://zhuanlan.zhihu.com/p/57062205

[4]、https://zhuanlan.zhihu.com/p/25071913

