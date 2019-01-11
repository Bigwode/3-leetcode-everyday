### Siamese Neural Networks. 

1、数据读取：**构造pairs**

每次返回两张图片和一个label（是否相同类别）

**方法1：** 按相同比例随机生成0和1，这样做是为了保证正负样本比例尽量一致。

当为1时，需选择两张相同类别的图片：先随机选一张，然后在while True中随机找一张图片，如果和之前找的那张是相同类的话跳出循环，否则再找一张；随机数为0的时候，就随机选一张就可以了。可能会出现相同的类，概率比较小。

**方法2：** 把每一个类的图片放到dict里，还是通过while找到不一样的样本对。



2、分别经过一个网络输出n维的特征，计算Contrastive Loss，注意这里的Y是当两张图片不是同一个类别的时候为1。
$$
Constractive \ Loss = (1-Y)\frac{1}{2}dis^2+Y\frac{1}{2}[max(0,(m-dis))]^2
$$
m是margin，dis是
$$
\Vert x \Vert _p := \left( \sum_{i=1}^n  \vert x_i \vert ^ p \right) ^ {1/p}
$$

```python
euclidean_distance = F.pairwise_distance(output1, output2)  
loss_contrastive = torch.mean((1-label) * torch.pow(euclidean_distance, 2) +     
(label) * torch.pow(torch.clamp(self.margin - euclidean_distance, min=0.0), 2))   # calmp夹断用法
```

##  Triplet Loss

和Contractive Loss损失函数不同的是，这里是用的是三元组进行训练，其他的都基本相同。

```python
losses = F.relu((anchor - positive).pow(2).sum(1) - (anchor - negative).pow(2).sum(1) + self.margin)
```

三元组的选取方式很重要，选的hard triplets应该是满足类内距离最大化并且类间距离最小化的三元组。

两种思路：

- 每隔n步离线生成triplets，使用最新的checkpoint并计算数据子集上的argmin和argmax。
- 在线生成triplets。 这可以通过从一个小批量中选择硬正/负范例来完成。



据说Triplet Loss训练起来收敛慢，但是效果可能要好一些。



**参考资料：**

[1]、https://www.cnblogs.com/king-lps/p/8342452.html

[2]、http://lawlite.me/2018/10/16/Triplet-Loss%E5%8E%9F%E7%90%86%E5%8F%8A%E5%85%B6%E5%AE%9E%E7%8E%B0/

