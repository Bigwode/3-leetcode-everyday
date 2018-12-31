## pytorch实用笔记

### 一、数据增强方法

注意顺序：随机裁剪 -> ToTensor -> Normalize

此处注意ToTensor作用是：convert a PIL image (H\*W\*C) in range[0, 255] to a tensor (C\*H\*W) in a range[0.0, 1.0] 即归一化的同时转换了通道顺序。

而Normalize输入的Tensor的size是(C,H,W)注意顺序。

### 二、定义Net

继承nn.Module，\_\_init\_\_()中设置上用到的组件，在forward中组装。

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











