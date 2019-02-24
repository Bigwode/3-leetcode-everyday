/*
题目：替换空格
思路：先统计字符串中的空格数量，将字符串后添加2×空格数
然后设置两个指针，分别指向原始字符串和新字符串的末尾，如果不是空格，移动字符元素之后，前移1位；若是空格，p1前移1位，p2前移3位，过程中将'02%'补充上。
*/

class Solution {
public:
	void replaceSpace(char *str,int length)
    {
        char* p = str;
        int count = 0;
        while(*p != '\0')
        {
            if(*p++ == ' ')
                ++count;
        }
        if(!count)
            return;

        char* p1 = p;
        char* p2 = p+count*2;
        while(p1 != p2)
        {
            if(*p1 != ' ')
                *p2-- = *p1--;
            else
            {
                --p1;
                *p2-- = '0';
                *p2-- = '2';
                *p2-- = '%';
            }
	}
};
