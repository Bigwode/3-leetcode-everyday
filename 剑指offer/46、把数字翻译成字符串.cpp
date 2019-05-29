/*
f(i) = f(i+1) + g(i, i+1)*f(i+2)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Num2StrCount(const string& s)
{
    int len = s.length();
    int count = 0;
    int* counts = new int[len];

    for(int i= len-1; i>=0; i--)  // 避免重复子问题，从末尾开始
    {
        if(i==len-1)
            count = 1;  // 针对最后一个数值
        else
            count = counts[i+1];
        if(i<len-1)
        {
            int num = (s[i] - '0')*10 + (s[i+1] - '0');  //　如果当前位和下一位构成的数字满足条件
            if(num>=10 && num<=25)
            {
                if(i<len-2)
                    count += counts[i+2];  //　考虑到最后两个元素，len-1和len-2的情况，没有f(i+1)+f(i+2)
                else
                    count += 1;  // 
            }
        }
        counts[i] = count;
    }
    count = counts[0];
    delete[] counts;
    return count;
}

int Num2StrCount(int number)
{
    if(number<0) return 0;
    string S = to_string(number);  // 转换为字符串，针对大数问题。
    return Num2StrCount(S);
}

int main()
{
    cout<< Num2StrCount(12258);
    return 0;
}

