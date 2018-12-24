**关于RCNN的一些问题总结**

RCNN测试过程[1]：

（1）SS选取2000个proposal

（2）Resize成227×227的方法：先在建议框的周围加上16个建议框像素平均值后直接resize成指定大小（各向异性变形），后输入CNN对每一个proposal进行特征提取4096维特征。

（3）将获得的2000×4096维特征与20个SVM组成的权值矩阵4096×20相乘，获得2000×20维矩阵表示每个建议框是某个物体类别的得分,分别对20类的每一列进行NMS。

（4）分别用20个回归器做BB回归

**问题１：为什么不直接使用CNN分类而训练多个SVM进行分类呢？**

CNN训练的时候，需要比较多的样本，而不强调精准的位置，所以将重叠IOU大于0.5的标记为了正样本，小于0.5标记为负样本。这样的标注导致直接使用CNN分类效果并不好。而使用SVM分类就不需要这么多样本了，所以就可以对训练数据有更加严格的标注[阈值为0.3]，分类效果更好一点。另外，softmax是在随机采样的背景样本上进行训练，而SVM采用的则是hard-negative mining，这提高了分类准确度。

**问题２：RCNN是如何设计回归器实现边界框回归？**[2]

![](regresstion)

如上图，黄色框P代表的是predict bb，绿色框G代表的是groundtruth bb，红色的框$\hat { G }$就代表的是我们想要把框回归到的位置。当P与G相差较小(IoU>0.6)时，可以认为是一种**线性变换**[3]，可以用简单的**最小二乘法**来解决这个线性回归问题。

我们定义窗口G,P,$\hat{G}$分别为，
$$
P=(P_x, P_y, P_w, P_h)\\
G = (G_x, G_y, G_w, G_h) \\
\hat{G} = (\hat{G}_x, \hat{G}_y, \hat{G}_w, \hat{G}_h)
\tag{1}
$$
其中，x,y为中心点坐标，w,h为宽和高。

我们定义了四个变换，
$$
d_x(P),d_y(P), d_w(P),d_h(P)
$$
分别为对x,y进行平移，对w,h进行缩放。如下式所示，
$$
\begin{aligned}
\hat{G}_x &= P_wd_x(P)+P_x\\
\hat{G}_y &= P_hd_y(P)+P_y\\
\hat{G}_w &= P_wexp(d_w(P)) \\
\hat{G}_h &= P_hexp(d_h(P))
\end{aligned}
\tag{2}
$$
其中，$d_*(P)$ [*为x,y,w,h]为AlexNet网络pool5层特征$\phi_5 (P)$的一个线性函数。可表示为，
$$
d_*(P) = w_*^T\phi _5(P)  \tag{3}
$$
这里的$w_*^T$代表的是我们要学习的回归参数。

我们的回归目标由式(2)按照(G, P)来计算得到，
$$
\begin{aligned}
t_x &= (G_x-P_x)/P_w \\
t_y &= (G_y-P_y)/P_h \\
t_w &= log(G_w/P_w) \\
t_h &= log(G_h/P_h)
\end{aligned}
\tag{4}
$$
回过头去看为何IoU>0.6可认为是线性变换，

我们都知道，
$$
\lim _{x=0}log(1+x) = x
$$
所以，
$$
t _ { w } = \log \left( G _ { w } / P _ { w } \right) = \log \left( \frac { G _ { w } + P _ { w } - P _ { w } } { P _ { w } } \right) = \log \left( 1 + \frac { G _ { w } - P _ { w } } { P _ { w } } \right)
$$
当$G_w$和$P_w$相等，$G_h$和$G_h$相等的时候才认为是线性函数。

那么我们的损失函数定义为，
$$
\text {Loss} = \operatorname { argmin } \sum _ { i = 0 } ^ { N } \left( t _ { * } ^ { i } - \hat { w } _ { * } ^ { T } \phi _ { 5 } \left( P ^ { i } \right) \right) ^ { 2 } + \lambda \left\| \hat { w } _ { * } \right\| ^ { 2 }
$$
这是一个典型的最小二乘问题（有正则项）。

------

那么我们接下来来回顾一下最小二乘法的矩阵法解法[4]。

假设函数
$$
h _ { \theta } \left( x _ { 1 } , x _ { 2 } , \ldots x _ { n } \right) = \theta _ { 0 } + \theta _ { 1 } x _ { 1 } + \ldots + \theta _ { n - 1 } x _ { n - 1 }
$$
的矩阵表达式为，
$$
h _ { \theta } ( \mathbf { x } ) = \mathbf { X } \theta
$$
其中，$\mathbf { X } $为m×n的矩阵，m为样本数，n为特征数，$\theta$为n×1参数量。

损失函数定义为，
$$
J ( \theta ) = \frac { 1 } { 2 } ( \mathbf { X } \theta - \mathbf { Y } ) ^ { T } ( \mathbf { X } \theta - \mathbf { Y } )
$$
根据最小二乘法的原理，对$\theta$求导等于0，可得
$$
\theta = \left( \mathbf { X } ^ { \mathrm { T } } \mathbf { X } \right) ^ { - 1 } \mathbf { X } ^ { \mathrm { T } } \mathbf { Y }
$$
这里面利用了两个矩阵求导公式，
$$
\frac { \partial } { \partial \theta } ( \mathbf { X } \theta ) = \mathbf { X } ^ { \mathbf { T } }\\
\frac { \partial } { \partial \theta } ( \theta^TA\theta ) = 2A { \theta}\\
$$
有正则项对$\theta$求偏导为，
$$
\mathbf { X } ^ { \mathrm { T } } ( \mathbf { X } \theta - \mathbf { Y } ) + \lambda \theta = 0
$$
得，
$$
\theta = \left( \mathbf { X } ^ { \mathrm { T } } \mathbf { X } + \lambda \mathbf { E } \right) ^ { - 1 } \mathbf { X } ^ { \mathrm { T } } \mathbf { Y }
$$
[1]、https://github.com/amusi/paper-note/blob/master/Object-Detection/R-CNN%E8%AE%BA%E6%96%87%E7%AC%94%E8%AE%B0.md

[2]、https://blog.csdn.net/wopawn/article/details/52133338

[3]、https://blog.csdn.net/zijin0802034/article/details/77685438

[4]、https://www.cnblogs.com/pinard/p/5976811.html

