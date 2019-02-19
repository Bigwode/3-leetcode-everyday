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