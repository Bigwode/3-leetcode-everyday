## Matching Networks for One-Shot Learning笔记

#### 1、构造数据集

对于Omniglot数据集，共1623个手写字符，每个字符20个样本。

分别划分1200和423张用来训练和验证。

X_train = [1200, 20, 28, 28, 1]

X_val = [423, 20, 28, 28, 1]

以此构建train_size=64000, val_size=20000的数据集。

返回的是：A list with [support_set_x+target_x, support_set_y, target_y]

挑选步骤：随机从1200/423个class中挑选出5个作为support class，随机从每个support class的20个样本中挑选出1个样本，放在前5位上，第6位放从support 5个类中随机挑选的1个test class中的1个随机样本。

slice_x = [5+1, 28, 28, 1]

slice_y = [5,]

```python
data.datasets_cache={'train':tuple([64000,6,28,28,1], [64000,5,5], [64000,5]),
                     'val':tuple([20000,6,28,28,1], [20000,5,5], [20000,5])}
```

#### 2、搭建网络结构

搭建一个简单的由卷积层，BN层和池化层叠加的CNN Image Embedding Model。

已知support set(S)和一张test example。
$$
S=\begin{Bmatrix}
(x_i,y_i)
\end{Bmatrix}_{i=1}^{k}
$$
对测试样本的分类函数是a linear combination of the labels in the surpport set（attention机制），即：
$$
P(\widehat{y}|\widehat{x},S)=\sum_{i=1}^{k}a(\widehat{x},x_i)y_i
$$
其中，a(.)函数是测试样例和集合样例特征的余弦相似度的softmax，即：
$$
a(\widehat{x},x_i)=\frac{e^{cosine(f(\widehat{x}),g(x_i)))}}{\sum_{j=1}^{k}e^{cosine(f(\widehat{x}),g(x_j))}}
$$
可以将a()函数看成是一个attention kernel，模型的预测结果就是support set中attention最多的图片所对应的label。f()和g()函数作用是把样例转变为向量化形式。

最后输出的就是对每个support class的概率，这样就可以直接使用`categorical_crossentropy`损失函数。

**keras中的Lambda层使用总结：**

如果只是想对流经该层的数据做个变换，而这个变换本身没有什么需要学习的参数，那么可以用Lambda Layer。

```python
keras.layers.Lambda(function, output_shape=None, mask=None, arguments=None)
```

**Merge()层使用总结：**

Merge层提供了一系列用于融合两个层或两个张量的层对象和方法。

```python
keras.engine.topology.Merge(layers=None, mode='sum', concat_axis=-1, dot_axes=-1, output_shape=None, node_indices=None, tensor_indices=None, name=None)
# layers：该参数为Keras张量的列表，或Keras层对象的列表。该列表的元素数目必须大于1。
# mode：合并模式，如果为字符串，则为下列值之一{“sum”，“mul”，“concat”，“ave”，“cos”，“dot”}
```



**用到的一些函数总结：**

```python
np.random.permutation(n)  # 生成n个数的随机数列
np.random.choice(a, size=None, replace=True, p=None)  
# a : 如果是一维数组，就表示从这个一维数组中随机采样；如果是int型，就表示从0到a-1这个序列中随机采样。
# replace采样是否有重复。
tf.rsqrt()  # 求平方根的倒数
```



**FCE（Full Context Embeddings）**

即将f和g函数不仅和输入的样例有关，还和support set的样例有关，即变成，
$$
g(x_i, S);f(\widehat{x}, S)
$$
*嵌入函数同时考虑support set和test set可以消除随机选择造成的差异性。增大差异性？？？*

论文中使用a bidirectional Long-Short Term Memory (LSTM)实现，

在代码中可以体现为，

分别将support set中的5个样例和test set中的样例两两一组进行saimese-like操作，即求差之后绝对值。得到pairwiseinteractions；test set中的样例和support set中的5个样例分别做同样的操作得到targetinteractions。

将得到的interactions相当于求Max pooling之后再送入CNN层中，之后的操作和之前的是一样的了。



#### 参考资料：

[1]、https://zhuanlan.zhihu.com/p/35797444

[2]、https://blog.csdn.net/hustqb/article/details/83861134

[3]、https://blog.csdn.net/feitianlzk/article/details/79455317