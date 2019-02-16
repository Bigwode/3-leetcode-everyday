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

1、函数名以_结尾的都是inplace方式，会直接修改数据本身。只有少数的autograd操作支持inplace操作，例如relu，因为其只需要根据输出就能够推算出反向传播的梯度，这样可以节省内存。

2、torch.gather(input, dim, index)  #按照index的索引，获取在dim轴上的值。

其中，index的dimensions必须和input一致。注意是沿着dim维度变化的方向索引。

3、Variable支持大部分tensor支持的函数，但不支持部分inplace函数，因为这会修改tensor本身，而在反向传播过程中Variable需要缓存原来的tensor来计算梯度。

4、非叶子节点梯度计算完成之后自动清空，反向传播过程中查看中间节点的梯度，使用autograd.grad函数或者hook.

```python
/*Method 1*/
torch.autograd.grad(z, y)  #相当于隐式调用backward()
/*Method 2*/
def variable_grad(grad):
    print(grad)
hook_handle = y.register_hook(variable_grad)
hook_handle.remove()  # 用完之后移除hook.
```

5、如何手写Function实现反向求导过程。

（1）自定义的Function需要继承autograd.Function，没有构造函数_\_init__ ，forward和backward都是静态方法。`@staticmethod`

```python
补充：一般来说，要使用某个类的方法，需要先实例化一个对象再调用方法。
而使用@staticmethod或@classmethod，就可以不需要实例化，直接类名.方法名()来调用。
两者的区别：
》@staticmethod不需要表示自身对象的self和自身类的cls参数，就跟使用函数一样。
》@classmethod也不需要self参数，但第一个参数需要是表示自身类的cls参数。

参考资料：https://blog.csdn.net/handsomekang/article/details/9615239
```

（2）其中forward函数的输入输出都是tensor，backward的输入输出都是variable。

（3）使用Function.apply(variable)即可调用实现的Function。

6、自定义层

继承nn.Module有意识地将输出变量都命名成x，是为了能让python回收一些中间层的输出，从而节省内存。

```python
torch.nn.Conv2d(in_channels, out_channels, kernel_size, stride=1, padding=0, dilation=1, groups=1, bias=True)
变量:
weight(tensor) - 卷积的权重，大小是(out_channels, in_channels,kernel_size)
bias(tensor) - 卷积的偏置系数，大小是（out_channel）
```

7、当模型有可学习的参数时，使用nn.Module()和没有可学习的参数时，可以使用nn.functional()，但是dropout使用nn.Module，因为其在训练和测试阶段不同。

有可学习的层，也可以使用functional代替，但是需要手动定义参数parameter。

8、多GPU并行计算。nn.parallel.data_parallel()直接利用多GPU并行计算；nn.DataParallel()返回一个新的module，能够自动在多GPU上进行并行计算。

9、搭建resnet50.

conv2d
$$
H_{out} = \left\lfloor\frac{H_{in}  + 2 \times \text{padding}[0] - \text{dilation}[0]
                        \times (\text{kernel_size}[0] - 1) - 1}{\text{stride}[0]} + 1\right\rfloor
$$
maxpool2d()
$$
\text{out}(N_i, C_j, h, w)  = \max_{m=0, \ldots, kH-1} \max_{n=0, \ldots, kW-1}
                               \text{input}(N_i, C_j, \text{stride}[0] * h + m, \text{stride}[1] * w + n)
$$
10、transforms可以通过Lambda封装自定义的转换策略。

ImageFolder() dataset.class_to_idx查看文件夹对应的映射关系。

高负荷的操作放在_\_getitem__中，例如读图片。

11、Dataloader默认Sampler是SequentialSampler，shuffle时是RandomSampler，当样本比例不均衡时，可以使用WeightedRandomSampler。

12、torch.set_default_tensor_type('torch.cuda.FloatTensor')

**13、pytorch的标签要转换为float32吗？**



**_\_getitem__如何保证在一个epoch里选的样本不重复？**

DataLoader()中的采样策略。

14、距离函数：F.pairwise_distance(x1,x2,p=2,eps=1e-6).   
$$
\Vert x \Vert _p := \left( \sum_{i=1}^n  \vert x_i \vert ^ p \right) ^ {1/p}
$$
公式中n是特征维度。

15、**model.train()和model.eval()** 

主要是针对model 在训练时和评价时不同的 Batch Normalization  和  Dropout 方法模式。

eval（）时，pytorch会自动把BN和DropOut固定住，不会取平均，而是用训练好的值。

不然的话，一旦test的batch_size过小，很容易就会被BN层导致生成图片颜色失真极大。

------

pytorch学习笔记

1、动态图与静态图。

动态图：每运行一行代码完成变量的新建或者一个操作的运算，在cuda里计算图完成一步。

静态图：先建好图，之后就不能动了，然后喂数据。tensorflow2.0动态库优先。

2、cuda加速

```python
torch.cuda.is_available()
device = torch.device('cuda')  # “cuda:0”
x.to(device)
```

3、自动求导

```python
grads = autograd.grad(y, [a, b, c])
```

4、梯度下降算法





