对于每个类别，都存在一个嵌入空间中的点，称为类的原型，每个样本的嵌入空间表示都会围绕这个点进行聚类。 为了做到这一点，即利用神经网络的非线性映射将输入映射到嵌入空间，并**将嵌入空间中支持集的平均值作为类的原型。** 预测分类的时候，就只需要比较跟支持集类别的哪个类的原型更近了。

简述一下几个训练过程：

（1）在所有的类别中随机选择K个类别的样本

（2）在K个类别的样本中，随机选择出每个类别的support set和query set，各M个

（3）通过CNN网络进行特征映射，并计算每个类的样本的特征向量平均值作为类原型，下图c（k）就是类原型。
$$
c_k=\frac{1}{\begin{vmatrix}
S_k
\end{vmatrix}}\sum_{(x_i,y_i)\in S_k}f_{\phi }(x_i)
$$
（4）计算quert set 的特征向量与K个类原型的距离，并通过softmax归一化，得到

quert set 所属类别的概率分布。
$$
p_{\phi }(y=k|x)=\frac{exp(-d(f_{\phi }(x),c_k))}{\sum_{{k}'}exp(-d(f_{\phi }(x),{c_k}'))}
$$


训练过程：在support set中，如果有n个种类，每个种类有m个样本，那么这个训练过程叫

n -way m-shot 

```python
--cuda -nsTr 1 -nsVa 1
number of random classes per episode for training            cTr=60;
number of samples per class to use as support for training   nsTr=1;
number of samples per class to use as query for training     nqTr=5;
number of random classes per episode for validation          cVa = 5;
number of samples per class to use as support for validation nsVa=1;
number of samples per class to use as query for validation   nqVa=15;

batch_size = 60*6 
x:[360, 1, 28, 28]
y:[360]
model_output:[360, 64]
num_support_tr=1;

```



```bash
== Downloading https://raw.githubusercontent.com/jakesnell/prototypical-networks/master/data/omniglot/splits/vinyals/train.txt
== Downloading https://raw.githubusercontent.com/jakesnell/prototypical-networks/master/data/omniglot/splits/vinyals/test.txt
== Downloading https://raw.githubusercontent.com/jakesnell/prototypical-networks/master/data/omniglot/splits/vinyals/trainval.txt
== Downloading https://raw.githubusercontent.com/jakesnell/prototypical-networks/master/data/omniglot/splits/vinyals/val.txt
== Downloading https://github.com/brendenlake/omniglot/raw/master/python/images_background.zip
== Unzip from ../dataset/raw/images_background.zip to ../dataset/raw
== Downloading https://github.com/brendenlake/omniglot/raw/master/python/images_evaluation.zip
== Unzip from ../dataset/raw/images_evaluation.zip to ../dataset/raw
Download finished.
== Dataset: Found 82240 items 
== Dataset: Found 4112 classes
== Dataset: Found 13760 items 
== Dataset: Found 688 classes
== Dataset: Found 33840 items 
== Dataset: Found 1692 classes
=== Epoch: 0 ===
100%|█████████████████████████████████████████| 100/100 [00:01<00:00, 51.47it/s]
Avg Train Loss: 1.49714834690094, Avg Train Acc: 0.5987666669487953
Avg Val Loss: 0.21838414795929567, Avg Val Acc: 0.9272000044584274 (Best)
=== Epoch: 99 ===
100%|█████████████████████████████████████████| 100/100 [00:01<00:00, 51.85it/s]
Avg Train Loss: 0.10759837854653596, Avg Train Acc: 0.964533331990242
Avg Val Loss: 0.052933967713024686, Avg Val Acc: 0.9876000046730041 (Best: 0.994400001168251)
Testing with last model..
Test Acc: 0.9840533381104469
Testing with best model..
Test Acc: 0.9849600045084953
```

