# 3-leetcode-everyday
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

**DAY 9**　每天加大量~_~GIVE ME FIVE!!!开心

283、move zeros

remove()删除列表中的某个元素但是如果元素有重复的只删除第一次出现的那个。

414、Third Max Number

1.sorted(list(set()), reverse=True降序)

2.构建一个三元素列表，依次比较。

448、查找不同元素，set(A).difference(B) (-也可以)

485、自己还是naive呀，一行代码

```python
return len(max(''.join(map(str, nums)).split('0')))
```

1.map()中arg2要是iterable的，max()用在单个str上，选的是第一个字符最大的那个，如果都一样选的是最长的

2.设两个变量，一个是当前的，一个是最终的，更新之

532、K-diff Pairs in an Array

最开始想得有点复杂了，考虑加k减k的情况，其实只考虑+k就可以了。

统计list中每个元素出现次数

collections.Counter()

------

**DAY 10** 

昨晚和师兄交流了一会儿，发现了近阶段自身存在的一些问题。１）太浮躁了，学东西过于求快，铺的面太广。作出一道题要充分领悟题目的内容，不能单纯贪图多！刷过的题复杂度不是最优的就不算是做对了！所以GIVE ME THREE吧，留给自己多一点的时间总结和思考！

２）想办法丰富自己的简历。把自己做的事情弄清楚！要给别人讲清楚！

561.Array Partition I

list[::2]间隔两个元素切片

566.Reshape the Matrix

读明白题再做

581.Shortest Unsorted Continuous Subarray

最开始的想法是从头到尾遍历，naive

zip();   all()

```python
return len(''.join(('.', ' ')[i==j] for i, j in zip(nums, sorted(nums))).strip())
```

605.Can Place Flowers

巧妙的是对开头和结尾两个元素的处理，在开头和结尾加了两个0，然后就可以以3为周期进行处理了

------

**DAY 11** 11.26

628.Max Product of Three Numbers

惊奇的发现对于排序后的数组来说，乘积最大值只可能出现的情况是

```python
return max(nums[-1] * nums[-2] * nums[-3], nums[0] * nums[1] * nums[-1])
```

**堆**

643.Max Average Subarray I

直接四个一组遍历求和会超出运行时间限制，因此只让后一个k元组的最后一个元素减去前一个k元组的第一个元素就是后一个求和多出来的部分。

13.Roman to Integer

------

**DAY 12** 11.27

14.Longest Commom Prefix

**zip()** 函数用于将可迭代的对象作为参数，将对象中对应的元素打包成一个个元组，然后返回由这些元组组成的列表。

zip() 和 * 操作符一起操作可以用来 unzip 一个列表

```python
for i, n in enumerate(zip(*strs))
```

20.Valid Parenheses

28.implement strStr()

find()函数

------

**DAY 13** 11.28

58.Length of Last Word

str.strip([chars])去掉首尾的指定字符，默认空格。

67.Add Binary

eval() 函数用来执行一个字符串表达式，并返回表达式的值。例如，eval('2+2')=4

eval('0b'+a) 二进制相加

bin()返回一个整数的二进制表示。

125.Valid Palindrome回文

```python
s = str(filter(str.isalnum, s)).lower()
return s == s[::-1]
```

不知道为什么线下对但是线上错误。

------

**DAY 14** 11.29

344.Reverse String EASY

345.Reverse Vowels of a string

学习python正则表达式！

re.findall('(?i)[aeiou]', s)

在字符串中匹配所有子串，并返回一个列表，如果没有找到匹配的，则返回空列表。

re.sub()用于替换字符串中的匹配项。

re.sub(r'\D', "", string)  # 从strings中将满足条件的字符使用""替换。

383.Ransom note勒索信

可以使用collections.Counter()对字符串每个元素进行统计。之后get(k, 0)方法获得相应元素的值。

------

**DAY 15**

387.First Unique Character in a String

统计字符串中每个字符出现的次数使用collections.Counter()

434.Number of Segments in a String

443.

459.Repeated Substring Pattern

find() 方法检测字符串中是否包含子字符串 str

```python
return (s*2)[1:-1].find(s) != -1
```
------

**DAY 16**

520.Detect Capital

看全转换为最大值和最小值之后的字符是否和原来的一样。

Python istitle() 方法检测字符串中所有的单词拼写首字母是否为大写，且其他字母为小写。

521.Longest  Uncommon Subsequence I

怪不得这个题这么多人给差评，只要是输出最长字符串的长度就可以

551.Student Attendance Record I

S.count('s')统计某个字符出现的次数。

------

**DAY 17**

557.Reverse Words in s String III

606.Constract String from Binary Tree涉及二叉树的前向遍历，以后做。

657.Robot Return to Origin

只需统计相应的个数是不是一样就行了！

------

**DAY 18**

9.Palindrome Number

69.Sqrt(x)

二分查找；牛顿法

168.Excel Sheet Column Title

26进制计数，ord()与chr()注意在'A'的基础上操作要减去1

------

**DAY 19**

171.Excel Sheet Columun Number

map()函数接收两个参数，一个是函数，一个是序列。map将传入的函数一次作用于序列的每一个元素，将结果作为新的list返回。

reduce()把一个函数作用在一个序列[x1,x2,...,]上，这个函数必须接受两个参数，reduce把结果继续和序列的下一个元素做累积计算。

```python
from functools import reduce
reduce(f, [x1, x2, x3, x4]) = f(f(f(x1, x2), x3), x4)
```

172.Factorial Trailing Zeros 即求阶乘最后有多少个0，没看懂。。。要求log复杂度

求n能被多少个５整除

202.Happy Numer

将结果放到一个set()里，通过看是否在set里有相同元素判断循环相加。如果循环到截止的元素不是１返回False.

------

**DAY 20**

21、Merge Two Sorted Lists.（链表）

将两个链表合并。注意dummy的使用或者使用递归。

83、Remove Duplicates from Sorted List.

------

**DAY 21**

141.Linked List Cycle　判断一个链表里是否有环

设两个指针slow和fast，分别一次移动一格和两格，如果在循环结束之前快的可以追上慢的，那么就说明有环。

注意终止条件的设置，设置不当的话可能会出现None.next的错误。



