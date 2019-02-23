# coding:utf-8
import numpy as np

# N 为batch size, D_in 为输入维度
# H 为隐藏层的维度, D_out 为输出的维度
N, D_in, H, D_out = 64, 1000, 100, 10

# 创建随机的输入和输出数据
x = np.random.randn(N, D_in)  # [64, 1000]
y = np.random.randn(N, D_out)  # [64, 10]

# 对两个隐藏层w1,w2进行初始化
w1 = np.random.randn(D_in, H)  # [1000, 100]
w2 = np.random.randn(H, D_out)  # [100, 10]

learning_rate = 1e-6
for t in range(500):
    h = x.dot(w1)  # [64, 1000]*[1000, 100] = [64, 100]
    h_relu = np.maximum(h, 0)  # [64, 100]
    y_pred = h_relu.dot(w2)  # [64, 100]*[100, 10]=[64, 10]

    loss = np.square(y_pred - y).sum()
    print(t, loss)

    # 反向传播根据loss更新w1和w2的值
    grad_y_pred = 2.0*(y_pred - y)  # [64, 10]
    grad_w2 = h_relu.T.dot(grad_y_pred)  # [64, 100].T *[64, 10] = [100, 10]
    grad_h_relu = grad_y_pred.dot(w2.T)  # 对h_relu求导 [64, 10]*[100, 10].T = [64, 100]
    grad_h = grad_h_relu.copy()
    grad_h[h < 0] = 0  # 经过relu, 将小于0的梯度归0
    grad_w1 = x.T.dot(grad_h)  # [64, 1000].T * [64, 100] = [1000, 100]

    # Update weights
    w1 = w1 - learning_rate * grad_w1
    w2 = w2 - learning_rate * grad_w2

