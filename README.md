# 3-leetcode-everyday
simple git course : https://blog.csdn.net/sinat_20177327/article/details/76062030

------

**DAY 1**

1、two-sum

**能同时获取元素和index的方法是使用enumerate()**
思路：从第一个元素开始，遍历，求每个位置上的**差值**保存到dict中，如果在接下来的元素在dict中出现，返回下标。。。真牛逼！

７、Reverse integer

**字符串[::-1]竟然是直接翻转字符串**

学会使用x=0 if x>0 else -1这样的表达式。

13、罗马数字转int

思路：从第二个值开始，如果当前值大于上一个值，则加的数是当前值减去上一个值的两倍！

14、longest Common Prefix

思路１：把每个位置上对应的字符放在set([])里，如果长度为１就加在res上，否则break

ps:可以通过**startswith()**判断字符串是否以某几个字符开头

思路２：没天理之**os.path.commonprefix(strs)**

------

**DAY 2**

及时发现，还是得按照不同的tag来做，这样才便于能找到其中的规律

```python
from collections import deque # 队列
```

**栈**

20、Valid Paratheses 可以使用list实现栈的相关操作

155、最小栈

------

**DAY 3**

476、find next greater element I **栈**牛比

思路：反其道而行之，从大的元素循环，往栈里放，如果后一个元素大于前一个元素，就把这个一个对儿弹出来放到字典中，最后从字典中找，get(x, -1)没有就返回-1

682、baseball game: str.isdigit()可以判断字符是否只数字，不能判断负数。

884、注意backspace同时出现的bug

------

**DAY 4** (投入英文leetcode第一天~_~  ) **Array对我好点～**

71、simplify path

这道题要是第一步想不到split('/')基本上就不好做了。

94、二叉树的中序遍历(还没学，学了再来)

（1）前序遍历（DLR），根-左-右。 
（2）中序遍历（LDR），左-根-右。 
（3）后序遍历（LRD），左-右-根。

26、Remove Duplicates from Sorted Array

27.remove element 遍历数组不要忘记while循环

------

**DAY 5**

35.Search Insert Position

53.Max Subarray　(@_@)

子串：数组中连续的若干个元素；子序列：只要求各元素的顺序与其在数组中一致，而没有连续的要求。

如果前一个值大于０，当前值加上前一个值。最后从里面选最大值。

66.Plus One

list(str)可以直接将str split成多个单元素的list

------

**DAY 6**

88.Merge sorted array

注意题目要求不需要返回任何值，只需要在原list上直接修改就可以了。

注意不要漏掉当if n>0的情况。

118, 119比较简单杨辉三角

------

**DAY 7**

**121、**从第１天往后的第i天，如果买出，赚得钱是第i-1天赚得钱 + [第i天的股价-第i-1天的股价]，如果不卖出，赚得钱是0。求之间的最大值（必须再做一遍）

167、Two Sum II - Input array is sorted

169、Majority Element

交换字典的键值顺序：my_dic = {u:v for v, u in dic.items()}

an impressive method：考虑到出现次数最多的值大于n/2，我们排序后的列表上选n//2位置上的值就是出现次数最多的值。

189、Rotate Array

在list中指定位置插入元素使用insert(id, x)

------

**DAY 8**

217、Contains Duplicate

219、Contains Duplicate II

更简单的方法是只要不满足减去上一个值小于k的就更新新的值。

268.Missing Number

set(A).difference(B)，在A中不在B中的元素。

sao操作，求和相减~

------

**DAY 9**

