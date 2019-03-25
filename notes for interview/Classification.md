##### 1、Inception系列

![这里写图片描述](https://img-blog.csdn.net/20161108152543838)

**V1：**将1x1，3x3，5x5的conv和3x3的pooling，stack在一起，一方面增加了网络的width，另一方面增加了网络对尺度的适应性。

**V2：** 针对V1，加入了BN层，较少了Internal Covariate Shift；使用两个3\*3的conv代替模块中的5\*5，降低了参数量的同时，加速计算。

![img](https://pic3.zhimg.com/80/v2-fa843c3f4bacbd516d97876a5278342a_hd.jpg)

**V3:** 把googlenet里一些7\*7的卷积变成了1\*7和7\*1的两层串联，3\*3的也一样，变成了1\*3和3\*1，这样加速了计算，还增加了网络的非线性，减小过拟合的概率。另外，网络的输入从224改成了299。

**V4:**　将原来卷积、池化的顺次连接（网络的前几层）替换为stem模块，来获得更深的网络结构。

Inception-Resnet模块。

Inception-Resnet V2中的Inception-resnet模块