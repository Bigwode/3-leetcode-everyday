# 3-leetcode-everyday
simple git course : https://blog.csdn.net/sinat_20177327/article/details/76062030

1、two-sum

**能同时获取元素和index的方法是使用enumerate()**
思路：从第一个元素开始，遍历，求每个位置上的**差值**保存到dict中，如果在接下来的元素在dict中出现，返回下标。。。真牛逼！

７、Reverse integer

**字符串[::-1]竟然是直接翻转字符串**

学会使用x=0 if x>0 else -1这样的表达式。

13、罗马数字转int

思路：从第二个值开始，如果当前值大于上一个值，则加的数是当前值减去上一个值的两倍！
