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

**DAY 20** ------链表

21、Merge Two Sorted Lists.（链表）

将两个链表合并。注意dummy的使用或者使用递归。

83、Remove Duplicates from Sorted List.

------

**DAY 21**

141.Linked List Cycle　判断一个链表里是否有环

设两个指针slow和fast，分别一次移动一格和两格，如果在循环结束之前快的可以追上慢的，那么就说明有环。

注意终止条件的设置，设置不当的话可能会出现None.next的错误。

160.Intersection of Two Linked Lists.

思路１：分别计算出两个链表的长度，然后move长的链表到短的链表长度，之后同时move两个指针，直到遇到相同的为止。时间O(2(m+n))，空间O(1)

思路2:同时循环两个链表，循环完一个再将指针移动到另一个开始，两次循环直到遇到相同的终止，或者没有交叉的情况结束。(dammmn this is ALgo, bro!)

203.Remove Linked List Elements

删除一个链表中val为某个值的结点。

思路：从头结点开始移到第一个值不是val的位置，判断是不是为空-> 如果dummy->next不为空，循环，如果dummy->next->val == val，就跳过下一个结点，否则就移动到下一个结点。

------

**DAY 22**

206.Reverse Linked List.翻转字符串

思路1:使用递归(recursively)

首先翻转第二个结点到最后一个结点的链表，然后再将头结点放到翻转链表的最后。

即，head->next->next = head; head->next = nullptr;

思路2:使用迭代(iteratively)

pre和cur连个指针都是从NULL开始，cur=head;head=head->next;cur->next =pre; pre = cur;

234.palindrome Linked List（one night~cmd）

思路1:创建一个逆序的链表，然后逐个比较是否相同。－－O(1) space条件不满足

思路2:利用快慢指针，将链表后半部分逆序，然后再对比。注意中间指针要赋为NULL。

------

**DAY 23**

237.Delete Node in a Linked List 额，这个题。

876.Middle of the Linked List　快慢指针真棒！

707.Design Linked List.设计链表及链表的基本操作，很全面的一个题。。

2.Add Two Numbers.

好题！注意两个链表长度不相等和链表尾有进位的情况。

------

**DAY 24**

19.Remove Nth Node from End of List.

思路：首先想到的还是快慢指针，注意几个特殊情况。例如，输入是[1],1，可能会出现null有指针的错误。也可能删除的元素在第一个位置上。所以，我们在开头新建一个空结点指向头指针，这样可以有效避免以上可能会出现的问题，

也可以新建一个指向头结点的指针slow实现相同的功能。注意这时候在整个过程中slow一直是指向指针的指针，而(\*slow) = (\*slow)->next;其实就相当于slow->next = slow->next->next;

24.Swap Nodes in Pairs.交换相邻的两个结点。

这样的题目使用递归肯定是可以做的。

迭代的做法需要注意指针交换的顺序。

61.Rotate List.

思路：先遍历一下求链表长度。将tail->next=head接起来，将tail向后移动len-k%len位，head是tail->next;然后tail->next = NULL;

------

**DAY 25**　**（链表的交换操作，链表的重点！）**

82.Remove Duplicates from Sorted List II

思路：感觉可能会删除第一个结点的操作都会有使用指向第一个结点的指针的指针或者新建一个空结点指向head，注意重复的数可能是连续多个，所以在遇到重复的值的时候，将cur指针先移动到最后一个重复的值，然后改变pre的指针，再移动cur指针。

86.Partition List.

思路：将list分为两段，小于x的连p，大于x的连q，最后再将p和q连接起来。

92.Reverse Linked List II

属于从第几个结点开始往后的元素开始翻转的问题。

------

**DAY 26**   **栈Stack**

关于标准库中stack的使用：

------------------------------------------------------------------------------------------

```c++
# include<stack>
stack<char> st; //初始化
for (char& c : s){}  //遍历
st.push(c); //进栈
st.empty(); //判断stack是否为空
st.top();　//返回栈顶元素，但不会删除
st.pop(); //出栈，但不会返回
st.size(); //返回栈中元素个数
```

**队列queue使用**

```c++
# include<queue>
queue<Type> q;
q.push(item); //进队
q.pop(); //删除队首，但不返回
q.front(); //返回队首，但是不删除
q.back(); //返回队尾，但是不删除
q.size(); //返回队中元素的个数
q.empty(); //判断队列是否为空
```

优先队列 priority queue.

优先队列是具有最高优先级的元素先出。





------------------------------------------------------------------------------------------

20.Valid Parentheses.

for(char c : s)会复制一个s字符串再进行遍历

for(char& c : s)会直接引用原字符串进行遍历操作。

155.Min Stack

使用两个栈，另一个是小于当前最小值就进栈。

225.Implement Stack using Queues.

232.Implement Queue using Stacks.

------

**DAY 27** 12.27



```c++
//先整理一下向量的基本操作
#include<vector>
vector型变量的声明及初始化
vector<int> a; // 无需制定数组长度，可以自我调整
vector<int> a(10);  // 大小为10
vector<int> a(10,1);  // 大小为10，初始值都为1
vector<int> b(a);
vector<int> b(a.begin(), a.begin()+3);  // 共三个元素
除此之外，还可以直接使用数组来初始化向量，
int n[] = {1,2,3,4,5};
vector<int> a(n, n+5);  //将数组前5个元素作为向量a的初始值。
vector<int> a(&n[0], &n[4]); //将n[1]-n[4],不包括n[4]的元素作为向量a的初始值。
//遍历
for(i=0; i<a.size(); i++)
	cout<<a[i]<<" " ;  //注意a[i]只能用于获取已存在的元素，不能用于赋值。
//向量中遍历器的类型为 vector<int>::iterator.
vector<int>::iterator t ;  // = a.begin();
for(t=a.begin(); t!=a.end(); t++)位置上
    cout<<*t<<" " ;
// 插入
a.insert(a.begin(), 1000);  // 将1000插入到起始位置
a.insert(a.begin(), 3, 1000); // 将1000分别插入到0-2位置上
a.push_back();  //尾部插入元素
//反转vector
reverse(a.begin(), a.end());
//删除
b.erase(b.begin());
b.erase(b.begin(), b.begin()+3);  // 删除元素
b.pop_back();  //删除最后一个元素
unique(); // 去除相邻重复元素
b.erase(unique(b.begin() ,b.end()),b.end());
即，
vector<int>::iterator iter = unique(ver.begin(),ver.end());
ver.erase(iter,ver.end());

// 创建二维数组
vector< vector<int> > b(10, vector<int>(5));  //创建一个10*5的int型二维向量
b.size()是行数，b[i].size()是列数。
//
b.back();  // 取最后一个元素
```

```c++
// unordered_map, undered_set与map, set用法的区别
unordered_map存储机制是哈希表，即内部元素是无序的。map是红黑树，map中的元素是按照二叉搜索树存储。
unordered_map<int, int> m;
m.count(key);  //如果key存在返回1，不存在返回0.
m.find(key) == m.end();  //如果key存在，则返回key对应的迭代器，不存在，则返回unordered_map::end
```



**参考资料：**

[1]、https://blog.csdn.net/szlcw1/article/details/23196065

[2]、https://www.cnblogs.com/mr-wid/archive/2013/01/22/2871105.html

496.Next Greater Element I.

使用unordered_map和stack结合，首先遍历大的vector，得到每个数值的next greater element，之后再从这里面查找，找不到的就push_back -1。

682.Baseball Game.

stoi(); string 2 int函数

844.Backspace String Compare.

------

**DAY 28** 12.28

933.Number of Recent Calls.

其实就是将queue中与当前元素差小于3000的元素pop()出来之后，返回剩余queue的size.

**Binary Search.专题**

35.Search Incert Position

如果直接循环vector去比较的话，时间复杂度是O(N)，不是最优。

STL中的lower_bound()返回的是nums中不小于target的值所在的iterator pointing。

```c++
return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
```

时间复杂度log(N)的做法是使用二分查找。

69.Sqrt(x)

注意溢出问题，能用除法不用乘法，能用局部循环不用全局循环。

------

**DAY 29**

167.Two Sum II - Input array is Sorted.

思路1 简单想法map法，但是O(n), vector配合undordered_map实现。

思路2：双指针法。在前后各设置一个指针，如果两数相加为target，就返回，否则，left和right或加或减。

思路3：二分查找，有点不efficient，偏麻烦。

278.First Bad Version.

二分法

349.Intersection of Two Arrays.

```c++
# set常用成员函数总结
set是使用红黑树实现的。
set<int> s(nums1.begin(), nums1.end());
begin()和end() 返回第一个元素和最后一个元素的迭代器。
count() //返回某个元素的个数
erase(i)  //删除元素
find() // 返回一个指向被查找元素的迭代器
insert() // 在集合中插入元素
lower_bound()  // 返回指向不小于某个值的第一个元素的迭代器
upper_bound() //大于

```



------

**DAY 30** 12.29

```c++
// map和unordered_map的区别
map是基于红黑树实现的，内部元素是有序的。而unordered_map是哈希表，内部无序。

```

350.Intersection of Two Arrays II

思路：结合unordered_map，统计出现次数，在另外一个里循环－1.

367.Valid Perfect Square.

必须得把mid的类型声明为long?不然会超出范围。

**Newton迭代法是怎么回事？感觉好简单！**

374.Guess Number Higher or Lower.

注意My number指的是pick的Number而不是你猜的number.题目说法上有问题。

------

**DAY 31**

441.Arraying Coins.

思路1：可以根据等差数列的求和公式来做。

思路2：使用二分法

475.Heaters.（×××）

思路：遍历house数组，**在heater里找到和每一个house距离最近的那个heater**，并求他们之间的距离为此house所需的半径，算出所有的house所需的半径，其中最大者即为要找的半径。

如果house比最大的heater还要大或者比heater最小的还要小的时候，就要使用最大或者最小的heater来cover。

如果heater中后面一个数的和当前house的差的绝对值<=前一个数和当前house位置差的绝对值，那么就继续遍历下一个位置？  最后我们返回的就是所有差值min里面的最大值。

704.Binary Search

744.Find Smallest Letter Greater than Target.

1.Two Sum感觉做过很多遍了

26.Remove Duplicates from Sorted Array.

这个题不能只是返回不重复的元素个数，还得直接在原来的数组上直接修改，前面的元素为不重复的元素。

统计重复元素的个数，遇到不重复的元素移动到上一个不重复的位置，即i-count

------

**DAY 32** **一定要扎实，沉得住气，不然相当于没做！**

27.Remove Element.

当会改变数组的长度的时候，用while。

53.Maximum Subarray.

如果前一个数大于零，后一个数就加上前一个数，最后取数组中的最大值。

动态规划解～还不会！

66.Plus One.

从最后一个往前判断是否等于9.等于9就直接变为0。

------

**DAY 33**

88.Merge Sorted Array.

也是从后往前比较大小后插入。

118.Pascal's Triangle

119.Pascal's Triangle II

------

**DAY 34**

121.Best Time to Buy and Sell Stock.

累加的思想，从第二个开始，看如果当前卖出的话收益是否大于max或者小于0。

大于max，更新max，小于0，收益置0。

122.Best Time to Buy and Sell Stock II.

相当于只要是后一个比前一个大，就累加；否则就相当于售出了，等下一次后一个比前一个大的时候再售出。

169.Majority Element.

最简单的方法就是排序，然后找最中间位置上的元素。

------

**DAY 35**

189.Rotate Array.

思路：k要对vector的size取余，将最后的k个数放到input的最前面，或者依次pop掉最后一个数insert到前面。

217.Contains Duplicate

219.Contains Duplicate II

思路：使用unordered_map记录当前值和坐标。

------

**DAY 36**

268.Missing Number.

求和相减，使用求和函数`accumulate(nums.begin(), nums.end(), 0)`

也可以不使用求和函数。

```c++
vector<int>nums = {0,1,2,4};
int miss = 0, i = 0;
for (int num : nums)
miss += ++i - num;
return miss;
```

正常情况下每次都加1，遇到缺失值之后的就不加了。很巧妙

283.Move Zeroes.

思路：设置一个新的变量j在遍历数组之后更新数组，最后如果j不到数组的长度就补0.

414.Third Maximum Number.

思路：不能通过初始化一个三个元素都是`INT_MIN`的数组，逐渐比较大小来查找最大的三个数，或者实现起来就比较麻烦了。或者换成`LONG_MIN`就好了

```c++
//注意vector中的查找要利用algorithms中的find(vector.begin(), vector.end(), elem)
注意插入到set里的元素默认从小到大排列。
```

****

**DAY 37** ---------**Hash Table.**

 136.Single Number.

思路：**位运算 XOR，异或**，不同为1，相同为0.级或运算满足交换律和结合律。所以最后剩下的元素就是没有只有单个的元素.

204.Count Primes.

**埃拉托斯特尼筛法**，sieve of Eratosthenes用来找出一定范围内的所有素数。复杂度是O(*n* log log *n*)

算法的伪代码：

```c++
fori=2,3,...,且不超过 根号下n;
if Primes[i]==true:
	for j = i**2,i**2+i,i**2+2i, ...不超过n:  //这里如果直接累加的话，会有重复的出现。
		Primes[i] = false;
count(check.begin(), check.end(), 1);
```

205.Isomorphic Strings. 同构字符串。

思路：字符串转换成数字串。即将两个字符串每个字符一一映射，下一次碰到这个字符的时候，判断来年各个字符对应的数字是否相同。用map也可以做。

初始化数组的大小是256，是因为整个ASCII的大小是256.

------

**DAY 38**

242.Valid Anagram.判断字符串是不是由同一组字构成的。

思路1：新建一个包含26个元素的数组，遍历的同时分别加一减一，判断最后是否数组元素全为0.

思路2：使用unordered_map遍历加一减一。

```c++
//unordered_map不会根据key的大小进行排序，存储时是根据key的hash值判断元素是否相同，即unordered_map内部元素是无序的，而map中的元素是按照二叉搜索树存储，进行中序遍历会得到有序遍历。
map采用红黑树的方式，而hash_map采用哈希的方法。
for (auto count : counts)
    if (count.second) return false;

unordered_map<char, int>::iterator it;
while(it != counts.end())
    if ((*it).second) return false;
    return true;
```

290.Word Pattern

```c++
//string 常用函数总结
[], at() //存取单一字符
data() //将内容以字符数组形式返回
substr() //返回某个子字符串
/*********分割字符串*********/
#include<sstream>
istringstream strcin(str);
string s;
vector<string> vs;
while(strcin >> s) vs.push_back(s);
```

最开始的思路：使用unordered_map有的元素就比较是否一致，没有的元素就添加到map里，但是遗漏的是不同的key会出现相同的value的情况。所以需要添加一个判断看是否m的value中有当前的值。

```c++
m.count(i) //判断某个元素是否在unordered_map中
for (auto count : m)
	if (count.second == v[i]) return false;  //遍历unordered_map,查看value.
```

387.First Unique Character in a String.

遍历两遍字符串，第一遍将每个char出现的次数存放在map或者vector中，第二遍从头看map中的值是否为1，即只出现一次。或者将map的second存放vector，一个位置放坐标，一个放出现的次数。

------

**DAY 39**

389.Find the Difference.

思路1：考虑到两个字符串无序，且元素个数不唯一，因此使用unordered_map()加一减一。8ms

```c++
string s.find(elem) //返回的是该元素第一次出现时所在的下标
```

思路2：同136，使用**异或**运算，这样遍历完两个字符串之后剩下的就是那个不一样的字符了。 4ms

409.Longest Palindrome.

思路1：unordered_map先统计每个元素出现的次数，然后再遍历map，找出.sencond分别为奇数的个数。用s.size()减去奇数的个数再加（odd>=1），4ms.

参考思路：使用count(s.begin(), s.end(), elem)计数之后，&1 求奇数的个数，最后再用字符串的长度减去技术的个数加（odd>0）。

438.Find All Anagrams(相同字母，异序词) in a String.

思路（naive）：遍历字符串，放到两个map里，比较两个map是否相同。每移动一次加上后边的元素，减去前面退出的元素，比较是否相同。

思路：放到两个vector中，**滑窗**从小的小字符串后开始，这样就可以滑到最后一个元素额。

```c++
{{,},{,}}; //map初始化方式
vector<int> sv(26, 0), pv(26, 0), res; //vector初始化方式
```

------

**DAY 40**

447.Number of Boomerangs.

题目：a tuple of points (i,j,k) such that the distance between i and j equals the distance between i and k(the order of the tuple matters)

思路：先遍历，即分别把每一个元素放到i位置上，再遍历分别求其他元素和i元素之间的距离，存放到map中，最后再遍历map，如果距离相等的有两个，就存在两种可能，如果有3个，就存在6中可能。。。（如果是三元组的话，最大可能是为2），因为不同顺序也算。

463.Island Perimeter

题目：将一个二维数组中的1看作是陆地，0看作是海洋。求陆地的周长。

思路：遍历数组，统计1的个数count以及，两个1相邻的个数mid，最后的结果是count*4-mid*2;

500.Keyboard Row.这题没意思

70.Climbing Stairs.

题目：有n阶楼梯，每一可以爬1个或者两个，问有多少种方式爬到最顶。

思路：动态规划，要想爬到第n层，有两种途径，一种是从n-1层爬1格，一种是从n-2层爬两格。所以到达第n层的步数steps[n]为steps[n-1]+steps[n-2]；

------

**DAY 41**

198.House Robber.

问题：从一个数组中找出多个不相邻的数使得它们的和最大。

思路：1.递归，第i个位置选与不选两种选择的最大值，如果选的话，就是当前的值加上n-2位置上两种选择的情况下的值的和；不选的话，就是n-1位置上的选与不选的情况下计算的值。超时～！

思路2：记忆式搜索。即，将当前的利益存到一个数组里面。从第三个元素开始，为到第三个位置上的两种途径的的选择所获得的利益的最大值。4ms

303.Range Sum Query -Immutable.

求数组中一个某个下标范围内的所有元素的和。用的是缓存？？？即把n个数的和都存起来，用的时候减去就可以了。那这样的话这个题就没什么意思额。-_--

746.Min Cost Climbing Stairs.

两种定义dp(n)的方式，一种是我们定义dp(n)为爬到第n阶楼梯的最小代价，即第n阶楼梯还不用花钱。

dp(n)=min(dp(n-1)+cost(n-1), dp(n-2)+cost[n-2]);

return dp(n);

第二种定义方式是，爬过第n阶楼梯所需要的最小代价，即第n阶楼梯需要花钱。

dp(n)=min(dp(n-1), dp(n-2))+cost[n];

return min(dp(n-1), dp(n-2));

我们可以使用三个变量来替代dp()数组保存的作用，这样就使得空间复杂度变成O(1)

------

**DAY 42** 1.14

100.Same Tree

判断两棵树是否相同。思路：递归

**DAY 43** 1.16

101.Symmetric Tree.

递归思路：判断左右两个节点的值是否相等；判断左分支的左支路是否和右分支的右支路互为镜像，左分支的右支路是否和右分支的左支路互为镜像，直到零节点。

104.Maximum Depth of Binary Tree.

求二叉树的最大深度：递归求二叉树的左子树和右子树的最大深度+1（头结点）。奥妙就在于+1使得从递归的最后一层开始累加。

107.Binary Tree Level Order Traversal II.*****

倒序层次遍历二叉树。

思路：先层次遍历二叉树，再使用reverse(v.begin(), v.end())进行倒序。

其中，层次遍历二叉树，使用递归，和视频中使用queue不一样的是，这里使用了一个curLevel参数来记录是哪一层，然后把当前结点的val值push到对应的层上去。

------

**DAY 44** 1.20

108.Convert Sorted Array to Binary Search Tree.

把一个升序排列的数组转换为一个高度平衡的二叉树：每个结点的两颗子树的深度差不大于1。

思路：每次在中间位置上new一个新的节点，(start, mid)和(mid+1, end)分别递归生成左右子树。

110.Balanced Binary Tree.

判断一个二叉树是不是height-balanced二叉树。

思路1：对于每个结点，计算其左右子树的depth()递归判断是否满足小于1的条件。复杂度：O(n^2)

思路2：

https://leetcode.com/problems/balanced-binary-tree/discuss/35691/The-bottom-up-O(N)-solution-would-be-better

111.Minimum Depth of Binary Tree.

求一个二叉树所有分支上的最小深度：分别求左右分支的最小深度的最小值。

------

**DAY 45** 1.27

112.Path Sum

判断一颗二叉树中root-to-leaf是否有sum的通路。

每过一个要减去当前的val值。当到叶子节点的时候，判断是不是sum==0了。递归调用函数分别看左右分支是否有满足条件的通路存在。

226.Invert Binary Tree.

交换二叉树的任意子树的左右分支：如果root==NULL 返回NULL，否则分别递归调用函数来交换左右子树，最后交换头结点的左右子树。

```bash
# 不同情况下github合并代码方法：
(1)远程仓库改变，而本地仓库没有改变的情况：
$ git remote -v  # 首先查看远程库
$ git fetch origin master  # 把远程库更新到本地
(2)远程库没有改变，本地库发生改变：
$ git status
$ git add .
$ git commit -m ""
$ git push -u origin master
(3)都有改变：
$ git log master.. origin/master  # 比较远程更新和本地库之间的差别
$ git merge origin/master  # 合并远程库

参考：http://scofieldwyq.github.io/2016/02/29/git%E4%BB%8E%E8%BF%9C%E7%A8%8B%E5%BA%93%E5%90%8C%E6%AD%A5%E5%88%B0%E6%9C%AC%E5%9C%B0%E4%BB%93%E5%BA%93/
```

235.Lowest Common Ancestor of a Binary Search Tree.

找到二叉搜索树中两个结点的最近的公共祖先(LCA)。其中一个结点可能是另外一个结点的祖先。

binary search tree.的属性：左子树包含结点的值小于等于右子树结点的值；

思路：如果p和q同时大于root的值，递归调用右分支求LCA，反之，同时小于root结点的值，递归调用左分支求LCA。否则root结点就是我们要找的结点。

------

**DAY 46**

257.Binary Tree Paths

题目：二叉树的所有root-to-leaf通路

思路：深度遍历左子树和右子树，累计字符串，到叶子节点push进vector。

to_string()转换为字符串。

404.Sum of Left Leaves

求二叉树所有左叶子的和。

思路：递归，设置一个isleft参数控制是否是左叶子，当到达叶子结点的时候，如果是左叶子就返回叶子的值，否则返回0。最终的结果是sumOfLeftLeaves(root->left, true)+sumOfLeftLeaves(root->right, false);

429.N-ary Tree Level Order Traversal

给一个n-ary的树，返回层次遍历的结果。

思路：

------

**DAY 47** 2.17

687.Longest Univalue Path

题目：给定一棵二叉树，找到最长的一条路径，路径上的所有结点有相同的值，可能经过根节点，也可能不经过根节点。返回的是路径的边数。

思路：

------

**DAY 48** 2.23 剑指offer，来吧！

**问题0:求链表的倒数第k个节点**

双指针法，快指针先走k-1步，慢指针才开始走，直到快指针走到最后一个节点，慢指针就是倒数第k个节点。

**题目3-1：找出长度为n的数组(所有元素都在0~n-1之间)中的一个重复元素(允许修改数组)**

思路：
（1）先判断输入是否满足条件，即，输入的数组是不是空指针；数组的长度是不是小于0以及数组中的数字是不是在规定范围内。
（2）循环遍历数组，如果当前值m和下标i是否相同？如果相同，跳到下一个元素；如果不同，先判断当前值和以当前值为坐标的位置上的值是不是相等，如果相等，就说明是重复的数字，否则，交换当前值和以当前值为下标的数值，继续判断这一过程。

```C++
for(int i=0;i<length;i++)
{
  while(numbers[i] != i)
  {
    if(numbers[i] == numbers[numbers[i]])
      return true;
    else:
      // swap numbers[i] and numbers[numbers[i]]
  }
}
```

时间复杂度O(n)；空间复杂度O(1)

**题目3-2：找出数组中的一个重复元素(不允许修改数组)**

思路2：使用unordered_map,空间复杂度O(n);时间复杂度O(n)

思路3：把1~n的数字从中间的数字m分成两部分，统计数组中数值在1~m之间的个数，如果大于m，一定包含重复的数字。时间复杂度：O(nlogn)，空间复杂度：O(1)

**题目4-1：二维数组元素的查找**

排好序的二维数组中元素的查找
需要从右上角或者左下角开始找,以此判断左上角的值和待查找的值的大小，判断是行下移或者列左移。

```C++
vector <vector<int>> array(3);  // 二维数组的初始化
for (int i = 0; i <3; i++)
  array[i].resize(3);
for (int i = 0; i <3; i++)
  for (int j = 0; j <3; j++)
    array[i][j] = (i*j);
/*Method 2*/
vector<vector<int>> b(10, vector<int>(5));
b.size()  // 行数
b[i].size()  // 列数
```

字符串：当几个指针赋值给相同的常量字符串时，他们实际上会指向相同的内存地址。

**题目5：替换空格**
思路：先统计字符串中的空格数量，将字符串后添加2×空格数
然后设置两个指针，分别指向原始字符串和新字符串的末尾，如果不是空格，移动字符元素之后，前移1位；若是空格，p1前移1位，p2前移3位，过程中将'02%'补充上。**（双指针法）**

时间复杂度：O(n)

------

**DAY 49** 2.24

```C++
struct ListNode{  // 链表
  int m_value;
  ListNode* m_pNext;
}
```

**题目6-0 ：删除链表中值为某数的元素**

思路：先找到第一个不为某数的节点，然后遍历判断，下一个节点是不是等于该值：如果等于，则dummy->next = dummy->next->next;否则，dummy = dummy->next。

**题目6：从尾到头打印链表**

思路：显式调用栈（或者使用vector.insert()函数直接在数组的begin()位置上直接插入），或者使用递归，这样退出递归的时候，将元素push进vector就是倒序打印链表。

**问题7-0 树的遍历：前序遍历；中序遍历；后序遍历；宽度优先遍历** 的递归和非递归实现（××××××重点）

二叉树的层次遍历：

将根节点入队；

队不为空时循环：从队列中出列一个节点*p，访问它；

将它的左右孩子进队。

**问题7-1根据前序遍历和后序遍历重建二叉树**

在pre中找到第一个元素，TreeNode* p = new TreeNode(pre[0]); 

在in中找这个元素所在的位置，将pre和in分隔开。再递归调用函数分别建立左子树和右子树。

注意：注意别忘了写递归的退出条件，即，当左右数组长度为0的时候，返回空指针。

时间复杂度：O(nlogn)；空间复杂度:O(n)

参考：https://blog.csdn.net/hellozmz/article/details/53331851

**问题8、二叉树的中序遍历的下一个节点**

如果有右子树：返回右子树的最左节点；

如果没有右子树：

(1)如果这个节点是其父节点的左子节点，那么它下一个节点就是它的父节点

(2)这个节点是其父节点的右子节点，沿着指向父节点的指针一直向上遍历，**直到找到一个是它父节点的左子节点的节点**（没有右子树的情况均可归纳为这种），如果这样的节点存在，那么它的父节点就是我们要找的下一个节点。

退到了根节点仍没找到满足这样条件的节点，则返回null

**问题9：用两个栈实现队列**

push的时候往1里push

pop的时候，先判断2是否为空，2为空，先把1弹出到2里，2不为空，先从2里往外依次弹出。

------

**DAY 50**  2.25

递归解法的问题：

每一次函数调用，都要在内存栈中分配内存空间，用来保存参数，返回地址和临时变量。还有一个问题是可能会出现**调用栈溢出**的情况。

**问题10、斐波那契数列**

思路：不使用递归的做法，因为时间复杂度会以n的指数递增。使用动态规划，从下往上计算，避免重复的计算。

**问题10-拓展1 青蛙跳台阶** 

注意初始的情况和斐波那契稍有不同。

**变态青蛙跳台阶**：一次可以跳1-n个台阶。可以通过推导求出总次数为2^n-1

**问题11-0 快速排序**（重点）

选一个中心点，先从后面移动小于的到前面来；再从前面移动一个大于的到后面去。

**问题11 旋转数组的最小数字** （二分法，双指针）

数组的旋转：将一个数组中前几个元素移动到数组的末尾

题目：输入一个递增排序数组的旋转，输出这个旋转数组的最小元素。

需要考虑的特殊情况：

当旋转的次数为0，即为原递增排序的数组，这时候不满足第一个元素比最后一个元素大的条件，这时候直接返回第一个元素就可以了；

或者是头指针和尾指针以及中间位置的数字相等的时候，就不能再继续用二分法，需要按照顺序依次查找最小的值。

**问题12：回溯法：判断矩阵中过是否有满足一个字符串输入的路径**

思路：需要设置一个数组记录矩阵中的元素是否被访问过，还要设置一个loc变量记录当前访问到的字符串中的位置。然后循环判断当前位置上的元素是否在字符串中。

在递归函数isThis()中，设置递归的退出条件:loc已经到字符串的末尾的位置上了，即'\0'。然后判断当前节点是否不超出矩阵边界并且等于当前字符串位置上的字符且没有被访问过，如果满足这个条件，先设置访问变量为1,被访问过的字符数加1，然后递归判断它的上下左右中找下一个元素是否在字符串中，没有就回退一个格并且将记录当前位置上的字符是否被访问过的变量设置为0。

**问题13：机器人的运动范围**

思路：判断当前节点是否满足可以访问的条件(不超出边界；各位数之和小于设定的阈值，并且还没有被访问过)

然后，递归该节点附近的其他四个节点求count的和

------

**DAY 51**  2.25

**问题14：剪绳子，使得乘积最大**

思路：1、动态规划：子问题得到了最优解，总的问题也就是最优解。

其实就是按照顺序，从小到大挨个试，将当前结果的最大值保存在数组中。

时间复杂度O($n^2$)和空间复杂度为O(n)。

2、贪婪算法：先尽量分割成3大小的，如果剩下4，就分割成2,2大小的。

时间复杂度和空间复杂度均为O(1)

**问题15：统计二进制中1的个数**

位运算：与或非，异或，左移和右移

右移的时候，看处理的数字是不是一个无符号数，如果是有符号数，左边补充的是数字的符号位。

考虑到输入的整数可能是负数，负数右移左侧补的是符号位，会造成死循环。所以要**左移无符号数unsigned int 1**，和该整数与操作，直到1变为0。

**惊喜的解法：**一个整数减去1与该整数按位与操作，会使得该整数最右边的1变为0，那么该整数有多少位1就进行多少次减一与的操作。

**相关题目1：**用一条语句判断一个整数是不是2的整数次方？思路：如果一个整数是2的整数次方，那么它的二进制表示中有且只有一位是1，所以执行一次减一与操作，看结果是不是就可以实现判断。

**相关题目2：** 输入两个整数m和n，改变多少个m的二进制位数才可以将m变为n？思路：先求异或，然后再统计异或中1的位数。

**问题16-0：字符串转数字**

**大数问题**：我们需要考虑会不会存在溢出，越界的情况，所以需要考虑用字符串或者数组来表示大的数字。

把错误信息传递给函数的调用者的三种方式：

用返回值来告知调用者是否出错；当错误发生时设置一个全局变量；函数出错时，抛出异常；

C++异常处理

```c++
try
{
   // 保护代码
}catch( ExceptionName e )
{
  // 处理 ExceptionName 异常的代码
}
if( b == 0 )
{
	throw "Division by zero condition!";
}
```

C++11标准可以使用stoi()函数直接转换string为int;

C++11之前可以使用<strstream>中的字符串流

```C++
int convertStringToInt(const string &s)
{
    int val;
    strstream ss;
    ss << s;
    ss >> val;
    return val;
}
```

问题16：数值的整数次方

注意当指数为负数的时候，和底数为0的情况；另外，指数大于0和小于0的情况分开考虑。

------

**DAY 52** 2.27

**题目17：打印从1到最大的n位数。**（大数问题）

```c++
memset(buf, 0, n); // 将buf填为n个0
```

注意可能会出现溢出的情况，所以应该使用字符串存储数字和实现依次加1。

设置进位标识符，当前位的值等于number[i] - '0' + over，只在最低位的时候才加1

打印的时候注意，前面的0不打印，需要跳过。判断是不是到了最大的999...9使用的是：判断最高位number[0]是不是产生了进位。

**补充题目：递归实现全排列**　（模模糊糊）

**题目18-1：O(1)时间内删除链表的节点**

思路：将要删除的节点的下一个节点的内容覆盖到待删除的节点，然后将待删除的节点的指针指向下一个节点的下一个节点。

需要考虑的特殊情况是：要删除的节点是尾节点（只能通过从头节点开始遍历到被删除的节点）或者要删除的节点是唯一节点（直接置为空节点）

注意 delete一个指针之后，一定要设为空指针，否则指针悬浮容易出问题。

**题目18-2：删除链表中的重复节点**　(***)

在一个排序的链表中删除重复的节点。

思路：为了应对头节点可能也是重复节点的情况，在头结点之前设置一个新节点。然后循环依次比较当前节点和下一节点的值是否相等：如果相等，继续移动下一个节点的指针，然后删除重复的节点；如果不相等，更新当前节点的指针的位置。

**题目19:正则项匹配**

需要注意的问题是：

\*str=='\0' && \*pattern!='\0'不能加是因为可能会出现（“”， “.*”）的情况。

先判断下一个字符是不是*号，如果是，看当前字符是否匹配（直接匹配或者是.匹配的情况），

匹配上的时候， 可以匹配0个，或者循环实现多个匹配，或者只匹配一个。递归实现；或者没有匹配上的时候，需要直接跳过两个。

如果下一个字符不是*：如果当前可字符匹配或者.匹配，则同时跳过一个字符；如果不满足两种匹配的条件，则返回false.

**题目20：表示数值的字符串**

判断整数部分是否包含含有正负号的整数s

判断小数部分是否包含无符号整数，小数点前后只需要有一方含有整数就可以

E/e的两侧必须都含有整数

注意这里传的参数是指向字符串指针的指针，保证字符串改变。

------

**DAY 53** 2.28

**21、调整数组顺序，保证奇数在偶数之前。（考虑不改变相对位置的情况）**

（1）、不考虑相对位置的情况，直接使用两个指针指向第一个元素和最后一个元素，或者使用下标前移和后移。判断奇数偶数考虑用与&运算符。

（2）、考虑相对位置可以使用两个vector拼接

```c++
odd.insert(odd.end(),even.begin(),even.end());
```

如果只是换个条件，例如，负数放在前面，能被3整除的放在前面。这时候我们可以写一个函数，传的是函数指针。bool(*func)(int)

**22、链表中倒数第k个节点**

设置快慢指针，快指针先走k-1步，从第k步开始，慢指针才开始走，直到快指针到达链表的最后一个节点，慢指针就是倒数第k个节点。

注意k可能比链表长度还要大的情况，注意在循环中判断，这时候返回的是nullptr。注意循环的退出条件。

**23、链表中环的入口节点**

首先应该判断链表中是否有环，通过设置快慢指针来判断。快指针一次走两步，慢指针一次走一步。若慢指针追上了快指针，则说明有环。如果走到末尾了还没有追上，就不包含环。

如果有环，返回相遇的节点，并且相遇的节点一定是处在环内的。然后从这个节点出发到再次回到这个节点的时候，统计环的长度m。

最后，从头结点开始，快指针先走m步，慢指针再开始走，直到两个指针相遇，即为入口节点。

**24、翻转列表**

为保证指针改变之后，链表不断开，需要保存当前节点之后的节点。所以会用到三个指针，分别指向前一个节点，当前节点和下一个节点。

**25、合并两个排好序的链表**

考虑非递归实现和递归实现两种做法。

```c++
if(pHead1->val <= pHead2->val)
{
  result = pHead1;
  result->next = Merge(pHead1->next, pHead2);
}
```



------

**DAY 54** 3.2

**26、判断一棵树是不是另一棵树的子树。**

思路：先找值相同的根节点；找到相同的根节点，然后判断是否是子树。

如果不是子树，递归查找左子树和右子树；如果子树为空是子树；如果子树不为空，但是大树为空不是子树。

**27、二叉树的镜像**

递归实现：当前节点不是根节点的时候，交换当前节点的左子树和右子树，左子树不为空，递归交换左子树；右子树不为空，递归交换右子树。

**28、对称的二叉树**

递归实现：递归判断左右两颗子树是否对称。递归判断pRoot1的左子树和pRoot2的右子树，以及pRoot1的右子树和pRoot2的左子树是否对称。

```c++
isSymmetrical(pRoot, pRoot);
```

**29、顺时针打印矩阵**

思路：循环继续的条件：while(rows > start\*2 && cols > start\*2)

**30、包含min函数的栈**

设置一个辅助栈，用来存放每次的最小值。

**31、栈的压入，弹出序列**

思路：循环，没遇到相等的，意味着还没有出栈，只完成入栈操作；遇到相等的，就不用入栈了；所有元素入栈结束，开始按照顺序出栈，直到所有元素出栈结束。

**32-0、从上到下打印二叉树**

使用queue实现二叉树的层次遍历。

定义`queue<TreeNode*> q;` 存放访问到的节点。

**32-1、分行从上到下打印二叉树**

清空vector的三种方式：

```c++
vector.clear();
使用迭代器vector.erase(iter);
vector<int>().swap(vector);
```

思路：需要设置两个变量来控制当前需要访问的节点个数和下一层需要访问的节点的个数。弹出一个，当前层节点数数减１，直到当前层处理完之后，重置当前层和下一层节点数。

**32-2、之字形打印二叉树**

思路：按之字形打印二叉树需要两个栈，如果当前打印的是奇数层，先保存左子节点再保存右子节点到第一个栈里；如果当前打印的层是偶数层，则先保存右子节点，再保存左子节点到第一个栈里。

同时，因为这里用了两个栈，所以不用再统计下一层节点的个数，所以只需要设置两个变量记录当前访问的层数是奇数层还是偶数层就可以了。

**33、二叉搜索树的后序遍历**

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。

二叉搜索树：左子树上所有节点的值小于根节点，右子树的所有节点的值大于根节点。

思路：最后一个节点是根节点，然后根据根节点的大小，从前往后遍历数组，将数组分成小于和大于根节点的两部分，其中，如果后面出现小于根节点的节点，返回false；在保证元素个数大于1的前提下，递归左右两部分数组。

```c++
if(i>0)  // 确保元素数大于1
    left = VerifySquenceOfBST(vector<int>(sequence.begin(), sequence.begin()+i));
bool right = true;
    if(i<len-1)  //  
         right = VerifySquenceOfBST(vector<int>(sequence.begin()+i, sequence.begin()+len-1));
```



------

**DAY 55**  3.5

**34、二叉树中和为某一个值的路径**

思路：按照前序遍历的顺序访问节点，将根节点加入当前路径中，如果到达叶子节点并且路径之和相等，将路径保存。如果没有到达叶子节点或者路径只和不相等，递归它的左子树和右子树。如果到达叶子节点但是不满足和的条件，退出路径中的最后一个值pop_back()。

------

**DAY 56**  3.8

**35、复杂链表的复制**

(1)、复制原始链表的任意节点N并创建新节点N'，再把N'链接到N的后面。

(2)、复制节点N的m_pSlibling指针,S'指向S的next。

(3)、按照奇数和偶数位置拆分两个链表。奇数位置上的节点是原始链表，偶数位置上的节点是复制出来的链表。初始化使得pNode在pClode之前，这样循环的终止条件简单一点。

**36、二叉搜索树和双向链表**(*\*\*\*\*)

> 二叉搜索树：若它的左子**树**不空，则左子**树**上所有结点的值均小于它的根结点的值； 若它的右子**树**不空，则右子**树**上所有结点的值均大于它的根结点的值； 它的左、右子**树**也分别为**二叉**排序**树**。

思路：设置递归退出条件，递归左子树，中找出左子树的最右节点，即双向链表的最后一个节点，若左子树不为空，将最后一个节点和根节点联系起来；递归右子树，若右子树不为空，将右子树和根节点连接起来。

```c++
    TreeNode* Convert(TreeNode* root)
    {
        if(root==nullptr)  return nullptr;  //递归边界
        if(root->left==nullptr && root->right==nullptr)  return root;  //递归边界

        TreeNode* left = Convert(root->left);  //递归左边
        TreeNode* p = left;
        while(p!=nullptr && p->right!=nullptr)  //找左子树最右节点
            p = p->right;  //当p->right为NULL的时候跳出循环
        if(left)  //若左子树不空
        {
            p->right = root;
            root->left = p;
        }
        TreeNode* right = Convert(root->right);  //递归右边
        if(right)  //若右子树不空
        {
            root->right = right;
            right->left = root;
        }
        return left ? left : root;
    }
```

**37、二叉树的序列化和反序列化**

序列化：将二叉树按照前序遍历保存到字符数组中；反序列化：二叉树恢复。

思路：根据前序遍历的顺序来序列化二叉树，当碰到nullptr指针的时候，将其序列化为一个特殊的字符（如'$'）,另外，节点的数值之间要用特殊字符隔开（如','）

**38、字符串的排列**

同17-1实现，没有考虑字符有重复的情况。

**拓展题目：八皇后问题** 

思路：对数组的index进行全排列，然后判断对于数组的两个下标，是否满足

i-j==colIndex[i]-colIndex[j]或者j-i==colIndex[i]-colIndex[j];

------

**DAY 57** 3.9

**39、数组中出现次数超过一半的数组**

思路1：快速排序＋取中间位置的数字

思路2：统计数字及其出现次数。如果下一个数字等于上一个数字，次数+1，否则，次数-1，当次数等于0的时候，统计下一个数。最后留下来的数字一定是出现次数大于数组长度一半的数字。最后注意检查该数字出现的次数是不是超过一半。

------

**DAY 58** 3.10

**40、最小的K个数**

思路1：类似于快速排序，使用Partion函数，找到index=k的时候前k个数即为最小的k个数。时间复杂度：O(n)，找到的前k个不是排好序的，只有在允许修改数组的时候才可以使用这种方法。

思路2：先创建一个k大小的容器，依次比较删除和插入。可以利用最大堆（可以在O(1)时间内找到已有的k个数字中的最大值，O(logk)时间完成删除及插入，所以总的时间复杂度O(nlogk)）和红黑树(红黑树的查找，删除和插入都是O(logk)时间复杂度)实现。特别适合处理海量数据。

```c++
set和multiset都是基于红黑树实现的，区别是multiset允许元素重复。
multiset<int, greater_set<int>> intset;
multiset<int, greater_set<int>>::itertor setIterator;
.insert();erase();
```

**41、数据流中的中位数**

如果从数据流中读出奇数个数值，中位数就是排序之后的中间的数值，如果是偶数个数值，中位数是所有数值排序之后的中间两个数的平均值。

```python
make_heap(_First, _Last, _Comp)  // 默认是建立最大堆的。对int类型，可以在第三个参数传入greater<int>()得到最小堆。
pop_heap();  // pop_heap()并没有删除元素，而是将堆顶元素和数组最后一个元素进行了替换，如果要删除这个元素，还需要对数组进行pop_back()操作。
push_heap(_First, _Last);  // 在堆中添加数据
```

前半部分使用最大堆，后半部分使用最小堆。当两个堆中的总数目为偶数的时候，把新数据加入最小堆，否则插入最大堆。如果此时（总数目是偶数，即应该是插入最小堆的），但是新数据比最大堆的最大值要小，就把最大堆的最大值弹出来插入最小堆，把最新值插入最大堆。当新数据应插入最大堆的时候，同理需要判断该元素和最小堆的最小值之间的大小关系。

**42、连续子数组的最大和**

思路：需要设置两个变量用来存放当前的和与和的最大值。当当前和小于0的时候，和改变为当前值。否则加上当前值，比较当前和与最大和的大小。判断是否更新最大和。

**43、1～n的所有整数中1出现的次数**

注意分析规律求logn复杂度解法。

如果weight=0,return round*base; if weight=1 return count+former+1; if weight>1 return count+base;(534=(53\*1+1) + (5\*10+10)+(0\*100+100) = 214)

参考博客：https://blog.csdn.net/yi_Afly/article/details/52012593

------

**DAY 59** 3.11

**44、数字序列中某一位的数字**

思路：以1001为例：

序列前10位为0-9，跳过，从后面找991位。

后180位为10-99,跳过，从后找991-180=811位。

后2700位为100-999， 因为811<2700，所以811在这三位数中的一位。

由于811=270*3+1，所以811是从100开始的第270个数字的中间一位。即7。（这里都是从0开始计数的）

**45、把数组排成最小的数**

隐形的大数问题，转换为字符串。

```c++
sort()函数　　// 三个参数：第一个是待排序数组的起始地址；第二个是结束的地址；第三个是排序的方法，默认的排序方法是从小到大排序。
```

**46、把数字翻译成字符串**

f(i) = f(i+1) + g(i, i+1)*f(i+2)

当i和i+1位满足条件的时候，g为1，否则为0。

**47、礼物的最大价值。**

一位数组优化版本，因为是先走的第一行，所以，maxValues数组中先保存的是第一行到头的最大值，因为只能往右走。然后，从第二行开始，前j个数保存的是第i行的前j个的最大值left，而后n-j个数保存的是上一行的最大值top。

------

**DAY 60**　3.12

**48、最长不含重复字符的子字符串**

思路：如果该字符没有出现或者距离上次出现的距离大于f(i-1)；

距离上次出现的位置小于或等于f(i-1)

**49、丑数**

只包含2,3,5因子的数成为丑数。按从小到大的顺序求第1500个丑数。1是第一个丑数。

思路1：逐个判断每个数是不是丑数，即如果被2整除，就除以2；被3整除就除以3；被5整除就除以5，最后一个数如果剩1的话，就是丑数。

思路2：以空间换取时间。丑数应该是另外一个丑数乘以235的结果。设置一个存放之前丑数的数组，每次需要更新比当前丑数小的位置。

**50、第一个只出现一次的字符**

**51、数组中的逆序对**

思路：直接使用循环的话时间复杂度是O(n^2)。考虑归并排序的思想做O(nlogn)，设置一个辅助数组。

初始化一个辅助数组，该数组作为存放临时排序的结果，最后要将排序的结果复制到原数组中。

https://www.nowcoder.com/questionTerminal/96bd6684e04a44eb80e6a68efc0ec6c5

**52、两个链表的第一个公共节点**

思路：长短链表有两个指针，长指针先走多出来的步数，然后再一起走，直到遇到相同的节点。

------

**DAY 61** 3.13

**53、在排序数组中查找数字**

思路：利用二分查找找到该数字在排序数组中的出现的第一个位置和最后一个位置。需要判断二分查找中间位置上的数是不是等于k，如果等于k的话，判断前一个数组或者后一个数字与k的大小关系。如果前一个比k小的话，说明第一次出现的位置就是中间位置，如果相等的话，第一次出现的位置在这之前。判断最后一个k出现的位置同理。

**54、二叉搜索树的第k大节点**

中序遍历，但是为什么加pNode != nullptr以及为什么返回的是pRoot?没搞懂！

**55-1、二叉树的深度**

递归(<)?1:2

**55-2、平衡二叉树**

判断一棵树是不是平衡二叉树：任意节点的左右子树深度不超过１

后序遍历树，记录每个节点的深度。

**56、数组中数字出现的次数**

找出一个数组中只出现一次的两个数字，其他的都出现两次。

可以使用异或的特性，考虑最后异或值最右侧为１的索引，按照这个位置上是不是为１将这个数组分成两部分，这样每个数组中只有一个只出现一次的数字了。

**56-2、数组中唯一只出现一次的数字，其他的都出现了三次。**

**57、和为s的数字**

思路：因为定义的数组是按照从小到大的顺序排好的了，所以我们定义两个指针，分别指向首和尾，依次相加判断大小，如果小的话，就将头指针右移，如果大的话，就将尾指针左移，直到和为给定的数为止。

**57-2、和为s的连续正数序列。**

在求和的时候用的技巧是：不用每次都全部求一边数组中所有元素的和，只需要push的时候，加上，r.erase(r.begin())的时候减去就可以了。

------

**DAY 62** 3.14

**58-1、翻转字符串**

思路：先翻转所有字的顺序，再翻转每个单词的顺序。

**58-2、左旋转字符串**

分别旋转两部分，之后再旋转整个字符串。

**59-1、滑动窗口的最大值**



**59-2、队列的最大值**

------

**DAY 63** 3.15

**60、n个骰子的点数**

**61、扑克牌中的顺子**

思路：首先把数组排序；然后统计０的个数；最后统计相邻数字之间空缺的次数。

注意，当相邻元素重复的时候，不可能是顺子。

```c++
qsort(numbers, length, sizeof(int), compare);
int compare(const void* arg1, const void* arg2)
{
  	return *(*int) arg1 - *(int*)arg2;  //升序排列
}
```

**62、圆圈中最后剩下的数字**

思路1：使用模板库中的std::list模拟环形链表

```C++
list<int>::iterator current = numbers.begin();
```

先移动到第m位置上，注意

```c++
if(current == numbers.end())
  	current = numbers.begin();
```

保存被删除节点的下一个节点next，然后删除当前节点，再把当前节点重置为next；最后返回*current.

思路2：

**63、股票的最大利润**

保存之前的最小的买入数值，然后求当前卖出的利润的最大值,即如果当前卖出赚的钱大于之前的最大值的话，那么这就是最大的利润。

**64、求1+2+...+n**

思路1:利用构造函数，创建n个该类型的实例，构造函数被调用n次。

注意：

```c++
静态成员变量在类中仅仅是声明，没有定义，所以要在类的外面定义，实际上是给静态成员变量分配内存。
如果不在类外定义，编译以上代码会出现“对‘A::a’未定义的引用”错误。这是因为静态成员变量a未定义，也就是还没有分配内存，显然是不可以访问的。
```

思路2:利用虚函数，可以设置递归的终点。

思路3:

思路4:

**65、不用加减乘除做加法**

三步走策略：先各位相加不进位（按位异或）；求进位（各位向与左移一位）；将前两步的结果相加；

（循环执行前两步，只到进位为0结束）

**67、把字符串转换为整数**

注意像空字符串，正负号等等非法输入的情况！还有必须设置当字符串输入为空的时候和输入为'0'的时候的两个0的区别。应该设置一个全局变量用来区分。

------

**DAY 64** 3.19 

1、Two Sum

```c++
unordered_map和map的区别:
// map:基于红黑树实现，红黑树具有自动排序的功能，因此map内部所有的数据，在任何时候，都是有序的。
unordered_map(hash_map) 
// 基于哈希表，数据插入和查找的时间复杂度很低，几乎是常数时间，而代价是消耗比较多的内存。
unordered_map<int, int> m;
m.count(cur)
set：红黑树实现。
```

使用struct和class来定义**类**，唯一的**区别**就是默认的访问权限不同。使用struct，那么默认为public成员，而使用class，那么默认为private。

------

**DAY 65** 3.20

**红黑树**：为了解决二叉搜索树（BST）多次插入新节点而导致的不平衡，红黑树（RBT）相应而生。

红黑树除了符合二叉搜索树的基本特征之外，还具备下列附加特性：

节点是红色或黑色；根节点是黑色；每个叶子节点都是黑色的空节点（NIL节点）；每个红色节点的两个子节点都是黑色(从每个叶子到根的所有路径上不能有两个连续的红色节点)；从任一节点到其每个叶子的所有路径都包含相同数目的黑色节点。

保证了红黑树的自平衡：红黑树从根到叶子的最长路径不会超过最短路径的２倍。

在插入新节点的时候，如果其父节点是红色，可能会打破红黑树的规则。应该进行调整，使其继续满足红黑树的规则：变色和旋转（左旋转和右旋转）。

------

**DAY 66** 5.8

leetcode 215. Kth Largest Element in an Array.

思路：

先判断数组的大小，如果很小，直接sort就可以了，另一种情况是k大于数组的长度，直接返回-1.

(1)最小堆解法(时间复杂度O(nlogk))

最小堆可以使用STL中的优先队列priority_queue实现，但是其默认是最大堆，需要修改为：

```c++
priority_queue<int, vector<int>, greater<int>> q;
```

最小堆思路：先往q中push前k个元素，然后依次比较剩余每个元素和top元素的大小，如果是大于q的top的元素，将q top的元素pop掉之后再push进该元素，最后返回top的元素就是第k大的数。

(2)类似于快排的思路，即递归partition。

快排思路：选定数组中的一个数作为pivot，将小于p的放右边，大于p的放左边。如果左边的数小于k个,则说明第k大的数在右边，接下来对右边的部分进行partion；如果左边的数大于k个，就对左边的部分进行partion，直到左半部分恰好有k-1个数，那个第k大的数就是pivot对应的数。

注意：partition一定要记住，这是解这一类题的模板。