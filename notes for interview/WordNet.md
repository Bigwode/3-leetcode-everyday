**NLTK wordnet使用教程**

使用wordnet需要下载omw, wordnet, wordnet_ic三个package[3]。

记录的内容参考官方API[1]和[2]

1、查询单词使用`synsets()`，包含(<lemma>,<pos>, <sense_number>)分别代表词条，词性和释义。

e.g. `wn.synset('dog.n.01')`

2、根据`definition()`和`examples()`查看某个释义对应的定义和例子。

e.g. `wn.synset('dog.n.01').definition()`

3、根据`part_meronyms()`， `substance_meronyms()`，`member_holonyms()`，`entailments()`来查看部分关系，实质关系，成员关系和蕴含关系。

e.g. 树的部分有树干、树冠； 树的实质是木材；树是森林的成员；eat包含咀嚼和下咽。

4、根据内部的关系树，计算两个词之间的相似度[4]。

e.g. 基于路径的方法

​     `synset1.path_similarity(synset2)`是基于上位词/下位词最短路径分词法；

​      `synset1.lch_similarity(synset2)`是基于最短路径和最大分类深度计算的Leacock-Chodorow相似度；

​      `synset1.wup_similarity(synset2)`是基于最大分类深度和最小公共包含（最具体的祖先节点）

基于互信息的方法

​     `synset1.res_similarity(synset2, ic)`基于信息内容(IC)最常见的包含(最具体的祖先节点)

​      `synset1.jcn_similarity(synset2, ic)`基于信息内容(IC)最常见的包含(最具体的祖先节点)和两个输入

​     `synset1.lin_similarity(synset2, ic)`

使用try...expect的时候，如果没有单词在词库中没有出现，返回的值适合上次一样的值。

5、根据`lowest_common_hypernyms()`查看两个词之间共同的上位词

e.g.  [Synset('car.n.01')] = `wn.synset('limousine.n.1').lowest_common_hypernyms(wn.synset('ambulance.n.1')) `

代表着豪华轿车和救护车都属于汽车。



**参考资料：**

[1] 、http://www.nltk.org/howto/wordnet.html

[2]、https://www.cnblogs.com/KingKou/p/4121373.html

[3]、https://zhuanlan.zhihu.com/p/26461511

[4]、https://blog.csdn.net/LRita/article/details/51149798