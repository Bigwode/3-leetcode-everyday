Mask R-CNN笔记

![img](https://img-blog.csdn.net/20180306103049920)

对这些ROI进行分类（N类别分类）、BB回归和Mask生成（在每一个ROI里面进行FCN操作）。

**RoI Pooling的两次量化误差**

(1)、原图的region proposal 映射到feature map 除以16或者32的时候边界出现小数，这是第一次量化。

(2)、在每个roi里划分成7\*7的bin，对每个bin的边界进行量化，每个bin使用max pooling，第二次量化。

**RoI Align过程：**

1 主干网：VGG16，stride = 32，原图800 x 800，最后一层特征图feature map大小：25 x 25 pix；

2 假定原图中有bbox reg后的proposal，大小为665 x 665 pix，这样，映射到feature map中的大小：665 / 32 = 20.78，即20.78 x 20.78 pix；----- **此处取消RoI Pooling中的第一次量化操作，不做bbox坐标的取整，而是保留浮点数；**

3 假定pooled_w = 7，pooled_h = 7，即pooling后固定成7 x 7 grid的特征图，将在 feature map上映射的20.78 x 20.78 pix的region proposal划分成49个同等大小的bin，每个bin的大小20.78 / 7 = 2.97 pix，即2.97 x 2.97尺度的bin；----- **此处取消RoI Pooling中的第二次量化操作，bin的坐标、尺度不做取整操作，而是保留浮点数；**

4 假定采样点数为4，即表示，对于每个2.97 x 2.97的bin，**平分四份小矩形，每一份取其中心点位置，而中心点位置的像素，采用双线性插值法进行计算**，这样就会得到四个点的像素值（对应上图fig 3）；

5 最后，**取四个像素值中最大值（max-pooling）作为这个bin的像素值**，如此类推，同样是49个bin得到49个像素值，组成7 x 7大小的feature map；

**Mask分支：**

对于每一个ROI，mask分支有K\*m\*m维度的输出，其对K个大小为m\*m的mask进行编码，每一个mask有K个类别。我们使用了per-pixel sigmoid，并且将Lmask定义为the average binary cross-entropy loss 。对应一个属于GT中的第k类的ROI，Lmask仅仅在第k个mask上面有定义（其它的k-1个mask输出对整个Loss没有贡献）。我们定义的Lmask允许网络为每一类生成一个mask，而不用和其它类进行竞争；我们依赖于分类分支所预测的类别标签来选择输出的mask。这样将分类和mask生成分解开来。这与利用FCN进行语义分割的有所不同，它通常使用一个per-pixel sigmoid和一个multinomial cross-entropy loss ，在这种情况下mask之间存在竞争关系；而由于我们使用了一个per-pixel sigmoid 和一个binary loss ，不同的mask之间不存在竞争关系。实验表明，这可以提高实例分割的效果。

- **将实例分割分解为分类和mask生成两个分支，依赖于分类分支所预测的类别标签来选择输出对应的mask。同时利用Binary Loss代替Multinomial Loss，消除了不同类别的mask之间的竞争，生成了准确的二值mask；**



参考资料：

[1]、https://zhuanlan.zhihu.com/p/46928697

[2]、https://blog.csdn.net/WZZ18191171661/article/details/79453780

[3]、https://blog.csdn.net/hnshahao/article/details/81231211 (号称全网最好的mask rcnn 解析?)

Detectron代码解析：

[4]、https://hellozhaozheng.github.io/z_post/Caffe2-Detectron-%E6%A8%A1%E5%9E%8B%E8%AE%AD%E7%BB%83/

[5]、https://ifreele.com/2018/03/22/tech-2018-3-22-faster-rcnn/