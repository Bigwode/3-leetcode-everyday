/*
 * 题目14：剪绳子
 * 一根长为length（大于1）的绳子，减成m（大于1）段，使其所有长度的乘积最大。
 * */
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


int maxProduct(int length)  // 动态规划 时间复杂度：O(n2) 空间复杂度：O(n)
{
    if(length < 2) return 0;
    if(length == 2) return 1;
    if(length == 3) return 2;

    int* res = new int[length+1];  // 这个数组是用来存储剪绳之后的乘积的最大值
    res[0] = 0;
    res[1] = 1;
    res[2] = 2;
    res[3] = 3;
    for(int i=4;i<=length; i++)
    {
        int max = 0;
        for(int j=1; j<=i/2; j++)　　// 是因为j和i-j在超过i/2的时候会重复
        {
            if(res[j]*res[i-j]>max)
                max = res[j]*res[i-j];
            res[i] = max;
        }
    }
    int product = res[length];
    delete[] res;
    return product;
}


int maxProduct2(int length)  // 贪婪算法 时间复杂度：O(1) 空间复杂度：O(1)
{
    if(length<2) return 0;
    if(length==2) return 1;
    if(length==3) return 2;
    int time3 = length/3;
    if(length%3==1)
        --time3;
    int time2 = (length-time3*3)/2;
    return int(pow(3, time3)*pow(2, time2));

}

int main()
{
    cout << maxProduct(13) << endl;
    cout << maxProduct2(13) << endl;
    return 0;
}
