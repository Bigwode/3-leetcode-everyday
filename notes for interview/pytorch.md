## pytorch实用笔记



### 一、数据增强方法

注意顺序：随机裁剪 -> ToTensor -> Normalize

此处注意ToTensor作用是：convert a PIL image (H\*W\*C) in range[0, 255] to a tensor (C\*H\*W) in a range[0.0, 1.0] 即归一化的同时转换了通道顺序。

而Normalize输入的Tensor的size是(C,H,W)注意顺序。

### 二、定义Net



```python
class Net(nn.Module):
  def __init__(self):
    # nn.Module的子类函数必须在构造函数中执行父类的构造函数。
    super(Net,self).__init__()  # 相当于nn.Module.__init__(self)
```

网络的可学习参数通过net.parameters()返回，net.named_parameters()同时返回名称及参数。

forward函数的输入和输出都是Variable，只有Variable才有自动求导功能。

因为计算的导数是累加的，所以在每次反向传播之前，所有参数的梯度清零optimizer.zero_grad()。

optimizer.step()用于更新参数。



### 三、权值初始化

torch.nn.init

### 四、Finetune权值初始化

```python
torch.save(pre_net.state_dict(), '.pkl')  # 保存一个训练好的模型
pretrained_dict = torch.load('.pkl')  # 加载模型的参数。
net = Net()  # 创建新的模型
net_state_dict = net.state_dict()  # 获取新模型的参数字典
pretrained_dict_l = {k:v for k,v in pretrained_dict.items() if k in net_state_dict}
# 将pretrained_dict里不属于net_state_dict的键去掉
net_state_dict.update(pretrained_dict_l)  # 然后更新新模型的参数字典
net.load_state_dict(net_state_dict)  # 最后，将更新了的参数字典放回到网络中

```

### 五、不同层设置不同的学习率

```python
conv5_params = list(map(id, net.conv5.parameters()))
conv4_params = list(map(id, net.conv4.parameters()))
base_params = filter(lambda p: id(p) not in conv5_params + conv4_params,
                     net.parameters())
optimizer = torch.optim.SGD([
            {'params': base_params},
            {'params': net.conv5.parameters(), 'lr': lr * 100},
            {'params': net.conv4.parameters(), 'lr': lr * 100},
            , lr=lr, momentum=0.9)

```

python **map()函数**：map(function, iterable, ...)

**filter()函数**：filter(function, iterable)过滤掉不符合条件的元素，返回由符合条件的元素组成的新列表。

**lambda()函数**：lambda 参数：操作（参数）

**reduce()函数**：对参数序列中的元素进行累积（即前两个元素计算得到的结果会再与第三个元素进行计算）。

如代码中所示，挑选出特定层的机制是利用**内存地址**作为过滤条件。

### 六、损失函数

1、交叉熵损失函数 CrossEntropyLoss。函数内部将输入先经过softmax激活函数，再计算交叉熵损失。

其weight(Tensor)参数可以设置用于解决类别不均衡问题。必须是float且长度和类别一致。

ignore_index(int)，忽略某一类别，不计算其loss。

output和target大小分别是(N,C)和(N,)

计算公式：
$$
loss(x, class) =-log\frac{exp(x[class])}{\sum_j exp(x[j])} =  -x[class]+log(\sum_j exp(x[j]))
$$
2、BCELoss()


$$
l(x,y) = \begin{Bmatrix}
l_1, ... , l_N
\end{Bmatrix},
l_n = -w_n[y_nlogx_n+(1-y_n)log(1-x_n)]
$$
BCEWithLogitsLoss()结合进了sigmoid。pos_weight设置正负样本的权重。

MarginRankingLoss()计算两个向量之间的相似度。

TripletMarginLoss() 计算三元组损失。让pos和anchor距离尽可能小，neg和anchor距离尽可能大。

### 七、优化器

1、在每一次更新前需zero_grad()

**python闭包：** 在一个内部函数中，对外部变量进行引用，并且一般外部变量的返回值为内部函数，那么内部函数就被认为是**闭包**。

### 八、监控模型---可视化

tensorboardX的函数：

add_scalar() 记录标量的变化，通常用于loss好人accuracy.

add_histogram()监测权值和梯度分布变化情况。

add_image_with_boxes()



### 九、其他

1、函数名以_结尾的都是inplace方式，会直接修改数据本身。

2、torch.gather(input, dim, index)  #按照index的索引，获取在dim轴上的值。

其中，index的dimensions必须和input一致。注意是沿着dim维度变化的方向索引。











