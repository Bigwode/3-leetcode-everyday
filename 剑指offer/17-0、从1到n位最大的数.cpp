/*
 * 题目17：打印从1到n的最大的n位数
 * */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


bool addOne(char* number, int length)
{
    int over = 0;  //进位标识符
    int currentNum = 0;
    for(int i=length-1; i>=0; i--)
    {
        currentNum = number[i] - '0' + over;
        if(i==length-1)  //最低位加1
            ++currentNum;
        if(currentNum >= 10)  // 大于10表示会产生进位
        {
            if(i==0)  // 如果进位是产生在最高位上
                return true;
            over = 1;  // 进位加1
            number[i] = '0' + currentNum-10;  // 当前位变成0,在循环对前一位进行操作
        }
        else
        {
            number[i] = '0' + currentNum;
            break;  // 不进位表示结束
        }
    }
    return false;
}

void printMax(char* number, int length)
{
    bool p = true;
    for(int i=0; i<length; i++)
    {
        if(p && number[i] != '0')  // 找到第一个不为0的数，接下来的数全部打印
            p = false;
        if(!p)
            cout << number[i];
    }
    cout << '\t';
}


void printNMax(int length)
{
    char* number = new char[length+1];
    memset(number, '0', length);
    number[length] = '\0';

    while(!addOne(number, length))  // 判断进位是否在最高位上，不在最高位上就打印当前值
    {
        printMax(number, length);
    }
    delete[] number;
}

int main()
{
    printNMax(4);
    return 0;
}
