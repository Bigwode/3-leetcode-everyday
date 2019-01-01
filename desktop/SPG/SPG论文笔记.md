**《Self-produced Guidance for Weakly-supervised Object Localization》论文笔记**

弱监督的方法大多是基于分类网络生成的attention maps来做的定位，然而attention maps只关注了图像中的一些small and discriminative parts，不是整个物体的完整区域。论文[2]中提出了一种generate Self-produced Guidence(SPG) masks，将物体从背景中分离出来来提供给分类网络一些像素之间的空间关联信息。这是一个stagewise的方法结合高置信度的物体区域学习SPG masks，并用来作为辅助的监督信息来facilitate分类网络的训练。

![图１、learning process of SPG](/home/david/桌面/SPG/learning process of SPG.png)

如图１所示，给定一张图片，先根据分类网络生成attention maps，然后根据attention maps的置信度将其分成object、background和undifined regions三部分Seed，其中具有medium confidence的undefined regions意味着这部分区域需要使用中间层的特征来弄清楚。SPG就是由这三部分seeds作为监督信息的multi-stage pixel-level object mask。

文章中指出也是这个作者的一篇文章提出的ACoL方法，忽略了像素之间的关联性。因为有关联的像素之间往往共享类似的表征，所以一些reliable 前景/背景区域可以通过这些discovered seeds来发现。文中使用了一种top-down机制，使用高层的输出作为底层的监督来学习物体的位置信息。上层包含更多的抽象的语义信息，而低层有一些更加具体的pixel-related信息。

![图２、The overview of SPG](/home/david/桌面/SPG/SPG-overview.png)

如图2所示，网络由Stem，SPG-A，B，C四部分组成。

其中，Stem和A1、A2部分来自Inception-V3结构，移除了Block3及以后的层。inception-V3结构如图3[1]所示。

![](/home/david/桌面/SPG/inception-V3.png)

A1,A2分别对应Inception-V3的Block1和block2，由此可以判断论文中的A1部分多画了一道杠。

A3部分是新添加上的两个卷积层，kernel_size=3，strides=1,pad=1 with 1024 fileters。

A4部分是一个1×1的卷积，stride=1 with 1000 units。最后是一层GAP。

B1和B2的第一层是3×3的卷积层with 288 and 768 filters, respectively.第二层是512 filters的卷积层，第三层是1×1的输出层。其中，B1和B2的第二、三层共享权重。

SPG-C是由两个3×3的卷积层with 512 filters 和一层1×1的输出层组成。

SPG Masks {0,1,255}是根据以下公式产生的，

![](/home/david/桌面/SPG/SPG-calculation.png)

两个参数是分离前景和背景的阈值。B1和B2两个阶段的阈值不一样，可以想到，B1阶段更小一点，因为前者生成的map更加模糊。训练过程中，值为255的不参与训练。O是由分类网络产生的attention maps。	

获得B1和B2输出之后，计算两个maps的均值作为Mfuse。

整个网络的训练过程如图4所示，

![](/home/david/桌面/SPG/SPG-al.png)

结合着图2，很清楚的就可以看明白。

**彩蛋时刻&致谢:**

怀着忐忑的心情联系了论文的原作者，悉尼科技大学博士，现在在UIUC魏云超组里交流。做相关方向有兴趣的同学可以follow大佬的相关工作[4]。 关于论文提出了自己的几个问题，作者也是很耐心的给予了回答。非常感激，在此也贴出问题及作者回答供大家学习参考。

**Q1：**论文中的示例图片大多是一些单物体且背景不是很复杂的，这样的图片我感觉用显著性检测的方法来分割和定位效果会更好一点吧。论文中提出的方法是否可以应用在包含多物体的图像中的物体定位？

**A1：**显著性检测的方法一般是有pixel level的supervision， SPG只利用了image-level的supervision信息。SPG应该稍微改一下就能用在多物体上，ACoL也可以。

**Q2：**不是很理解设计的网络结构中SPG-C的作用，因为在经过一个1*1的卷积之后的输出同样也用来监督低层的学习过程，两者有什么区别吗？（根据Inception V3网络结构中的模块设计，Fig.2.中SPG-A的A1的部分应该是多画了一道杠^_^）

**A2:** SPG-C用来给网络注入pixel-level的feedback信息，也就是piexl-level的监督信息，让网络同时学习classification和silency (A1好像是个mistake。。。)

**Q3：**是如何想到SPG-B1和SPG-B2的二三层共享权重的呢？整个网络是在ILSVRC2016上重新训练的吗？有没有利用迁移学习的相关方法，使用预训练权重微调结果试一试。如果论文中可以展示经过不同的迭代次数产生的masks不断变化的图就更好了。

**A3:**共享权重是ablition study做的一个实验，因为加了结构相同的模块，所以分别测试了共享和不共享的性能。网络是finetune的，个人认为没有必要展示mask的变化过程，一方面是比较intuitive，初始时很差，逐渐变好。另一方面是，imagenet数据很多，finetune一个epoch后的图片看起来和两个个epoch后的没有很大区别。

**Q4：**论文中在对比实验的时候使用的SPG-plain是不加SPG-B和SPG-C的结构训练的结果吗？SPG* using predictions with high scores是什么意思？造成top-5 err.比GT-known loc. err.还要低。

**A4:**1）是的； 2,3） SPG* 是follow了bolei zhou的测试代码，这部分我也没改，只是跑了个值。top-5 比GT低是合理的， 因为有可能gt class对应的map质量不一定比second highest score对应的map好。

参考资料：

[1]、https://www.jianshu.com/p/3bbf0675cfce

[2]、https://arxiv.org/abs/1807.08902

[3]、https://arxiv.org/abs/1804.06962

[4]、https://weiyc.github.io/

