# LearningToCompare_Relation Network笔记

PyTorch code for CVPR 2018 paper: [Learning to Compare: Relation Network for Few-Shot Learning](https://arxiv.org/abs/1711.06025) (Few-Shot Learning part)

For Zero-Shot Learning part, please visit [here](https://github.com/lzrobots/LearningToCompare_ZSL).



对于包含c个不同的类别，每个类别有k个样本的support set，本文称之为c-way k-shot。

我们有一个拥有大量数据的训练集（training set），我们利用这个训练集来构造出和测试时类似的数据结构，也就是**sample set**和**query set**来模拟**测试时的support set和testing set**。我们可以使用训练集来生成巨量的模拟任务，从而在meta层面上训练整个关系网络。我们把输出的relation score看做是一个从0到1的数值。0就代表极不相似，而1则代表完全相似。因此，我们就非常直接的采用平方差MSE作为网络训练的loss。



```python
task:{character_folder:[1200 path_to_images_classes],
		test_labels:[19*5(0-1)],
        num_classes=5;
		test_num=19;
		train_num=1;
		test_roots:[19*5 path_to_images],
		train_labels:[0,1,2,3,4],
		train_roots:[5 path_to_images]
		}
相当于验证阶段：TEST_EPISODE
task:{character_folder:[423 path_to_images_classes],
		test_labels:[1*5(0-1)],
        num_classes=5;
		test_num=1;  #训练时挑19个，测试时挑一个。
		train_num=1;
		test_roots:[1*5 path_to_images],
		train_labels:[0,1,2,3,4],
		train_roots:[5 path_to_images]
		}

sample_images=[5,1,28,28] ; sample_labels=[5]
test_images=[5,1,28,28] ; test_labels=[5]
```

```python
randperm功能是随机打乱一个数字序列。
语法格式：
y = torch.randperm(n)
y是把1到n这些数随机打乱得到的一个数字序列。

samples:[5,1,28,28]
sample_labels:[5]
batches:[19*5,1,28,28]
batch_labels:[95]
随机从1200个类中挑选出5个类，再从这每个类的20个样本中中分别挑出1和19个作为train和test.
(5L, 1L, 28L, 28L)
(5L, 64L, 13L, 13L)
(5L, 64L, 5L, 5L)
(5L, 64L, 5L, 5L)
(5L, 64L, 5L, 5L)
sample_features_ext:[19*5, 5, 64, 5, 5]
batch_features_ext:[5, 95, 64, 5, 5]->[95, 5, 64, 5, 5]
=============================================================
pytorch: 如何优雅的将 int list 转成 one-hot形式:
# LongTensor的shape刚好与x的shape对应，也就是LongTensor每个index指定x中一个数据的填充位置。dim=0，表示按行填充，主要理解按行填充。举例LongTensor中的第0行第2列index=2，表示在第2行（从0开始）进行填充，对应到zeros(3, 5)中就是位置（2,2）。所以此处要求zeros(3, 5)的列数要与x列数相同，而LongTensor中的index最大值应与zeros(3, 5)行数相一致。
>>> torch.zeros(3, 5).scatter_(0, torch.LongTensor([[0, 1, 2, 0, 0], [2, 0, 0, 1, 2]]), x)
# out[index[i, j], j] = value[i, j] dim=0
# out[i,index[i, j]] = value[i, j]] dim=1 

```

```python
a = torch.gather(0,16).view(4,4)
index = torch.LongTensor([[0,1,2,3]])
a.gather(0,index)  # get tensor([[0,5,10,15]])
```



------

# Requirements

Python 2.7

Pytorch 0.3

# Data

For Omniglot experiments, I directly attach omniglot 28x28 resized images in the git, which is created based on [omniglot](https://github.com/brendenlake/omniglot) and [maml](https://github.com/cbfinn/maml).

For mini-Imagenet experiments, please download [mini-Imagenet](https://drive.google.com/open?id=0B3Irx3uQNoBMQ1FlNXJsZUdYWEE) and put it in ./datas/mini-Imagenet and run proc_image.py to preprocess generate train/val/test datasets. (This process method is based on [maml](https://github.com/cbfinn/maml)).

# Train

omniglot 5way 1 shot:

```python
python omniglot_train_one_shot.py -w 5 -s 1 -b 19  # 默认设置
```

omniglot 5way 5 shot:

```
python omniglot_train_few_shot.py -w 5 -s 5 -b 15 
```

omniglot 20way 1 shot:

```
python omniglot_train_one_shot.py -w 20 -s 1 -b 10
```

omniglot 20way 5 shot:

```
python omniglot_train_few_shot.py -w 20 -s 5 -b 5
```

mini-Imagenet 5 way 1 shot:

```
python miniimagenet_train_one_shot.py -w 5 -s 1 -b 15
```

mini-Imagenet 5 way 5 shot:

```
python miniimagenet_train_few_shot.py -w 5 -s 5 -b 10
```

you can change -b parameter based on your GPU memory. Currently It will load my trained model, if you want to train from scratch, you can delete models by yourself.

## Test

omniglot 5way 1 shot:

```
python omniglot_test_one_shot.py -w 5 -s 1
```

Other experiments' testings are similar.


## Citing

If you use this code in your research, please use the following BibTeX entry.

```
@inproceedings{sung2018learning,
  title={Learning to Compare: Relation Network for Few-Shot Learning},
  author={Sung, Flood and Yang, Yongxin and Zhang, Li and Xiang, Tao and Torr, Philip HS and Hospedales, Timothy M},
  booktitle={Proceedings of the IEEE Conference on Computer Vision and Pattern Recognition},
  year={2018}
}
```

## Reference

[MAML](https://github.com/cbfinn/maml)

[MAML-pytorch](https://github.com/katerakelly/pytorch-maml)


