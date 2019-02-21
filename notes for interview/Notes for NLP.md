## Deep Learning in NLP 词向量

将词用“词向量”的方式表示可谓是将 Deep Learning 算法引入 NLP 领域的一个核心技术。

**词向量**具有良好的语义特性，是表示词语特征的常用方式。词向量的每一维的值代表一个具有一定的语义和语法上解释的特征。故可以将词向量的每一维称为一个**词语特征**。词向量用Distributed Representation表示，是一种稠密的低维实数向量。

使得基于衡量向量距离的方法（如欧式距离、余弦距离等）可以用来度量单词间的相似度。

**词向量-word2vec**

word2vec工具主要包含两个模型：跳字模型（skip-gram）和连续词袋模型（continuous bag of words, CBOW），以及两种高效的训练方法：负采样（negative sampling）和层序sofrmax。word2vec可以较好的表达不同词之间的相似和类比关系。

**跳字模型**：用一个词来预测它在文本序列周围的词。

给定中心词，生成背景词的联合概率：  
$$
\prod_{t=1}^{T}\prod_{-m\leq j\leq m} \mathbb{P}(\omega ^{t+j}|\omega ^{t})
$$
其中m为窗口大小，t为当前时刻的值。最大化联合概率相当于最小化损失函数：
$$
-\frac{1}{T}\sum_{t=1}^{T}\sum_{-m\leq j\leq m}log(\mathbb{P}(\omega ^{t+j}|\omega ^{t}))
$$
其中，
$$
\mathbb{P}(\omega _o|\omega _c) = \frac{exp(u_{o}^{T}v_c)}{\sum_{i\in V}exp(u_{i}^Tv_c)}
$$
其中，$w_c$为中心词，$w_o$为背景词，$v_c$为中心词词向量，$u_i$为背景词词向量。

然后利用随机梯度下降计算。

**连续词袋模型**：根据背景词生成中心词。

过程同跳字模型，即：
$$
\prod_{t=1}^T \mathbb{P}(\omega ^{t} | \omega^{t-m},..., \omega^{t-1}, \omega^{t+1},..., \omega^{t+m} )
$$
即最小化损失函数：
$$
-\sum _{t=1}^{T}log\mathbb{P}
$$
其中，
$$
\mathbb{P}=\frac{exp[u_c^{T}(v_{o1}+...+v_{om})/(2m)]}{\sum_{i\in V}exp([u_i^{T}(v_{o1}+...+v_{om})/(2m)])}
$$
GloVe使用了词与词之间的共现（co-occurrence）信息。

fastText在使用负采样的skip-gram模型的基础上，将每个中心词视为子词（subword）的集合，并学习子词的词向量。

**word2vec与GloVe的异同**

本质上来说，word2vec通过上下文预测中心词/通过中心词预测上下文的做法，也是基于词共现信息的一种建模方式。因此两者的共同点就是都能通过词的共现信息去学到词之间的关系。

不同之处在于，word2vec是一种“预测”模型，而GloVe是一种“计数”模型。预测模型的目的在于最小化损失函数以提高预测能力；而计数模型本质上是对词共现矩阵进行降维操作。

**Spot:使用一维卷积操作，和linear层进行性能比较**

