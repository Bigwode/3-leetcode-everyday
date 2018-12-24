BP Algorithm

本篇文章只考虑最简单的一种情况，只有两层并且没考虑偏置项，链式法则和梯度下降。

第i层的输出$y_i$，第i层的输入$x_j$，第i层的输出$y_j$，相当于只有一个隐层后接了一个sigmoid。


$$
\begin{aligned}
x_j &= \sum_{i}W_{ji}y_j\\
y_j &= \frac{1}{1+e^{-x_j}}\\
loss:L &= \frac{1}{2}\sum_{j}(y_j - {y_j}')^2\\
\frac{\partial L}{\partial W_{ji}} &= \frac{\partial L}{\partial y_j}\cdot \frac{\partial y_j}{\partial x_j}\cdot \frac{\partial x_j}{\partial W_{ji}}\\
&=    

\end{aligned}
$$


