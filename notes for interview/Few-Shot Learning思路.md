## **Dilemma(困境) of Large-scale Supervised Recognition.**

1、知识缺失 Knowledge learned is not retained.

知识的学习不能累积；不能利用过去学到的知识。Can't learn to learn.

2、Needs a large number of training examples.

### One-Shot Learning 研究主要分为以下两个类。

1、不使用辅助的data，直接学习一个one-shot classifier.

（1）基于实例instance的学习，如KNN

（2）非参数方法

2、基于迁移学习的方法：The Paradigm of learning to learn or meta-learning.

#### **目前面临的问题：**

one-shot detection大部分是在tracking任务中完成的，tracking的数据集更像是instance级别的检测，并且是多目标的。VOC或COCO数据集是类别级别的检测，任务的直接迁移效果待考察。

#### Multiple Object Tracking:多目标跟踪综述

Detection-Based Tracking(**DBT**) 和Detction-Free Tracking(**DFT**) 区别

![差异](https://img-blog.csdn.net/20171207212320245)

MOT分为**OnLine**跟踪与**OffLine**跟踪，Online用到的帧是直到当前帧的前面帧信息，Offline则可以用到未来帧信息。 

MOT16数据集上的大多数算法直接使用数据集里标注的检测结果，而不是自己检测。他们的精力主要在：遮挡；相似的外观；复杂的运动等方面。

MOT数据集的gt坐标更喜欢用左上角坐标和长宽。

不关注tracking物体的类别（有类别信息，但是区分度不高，例如Pedestrain；Person on Vehicle；Static Person）。

det.txt有用的字段：第几帧；坐标值。







https://blog.csdn.net/Kerrwy/article/details/80886492

**参考资料：**

Learning to learn:Model Regression Networks for easy small sample learning.

Matching networks for one shot learning.

prototypical networks for few-shot learning.

learning to compare : relation network for few-shot learning .
