/*
 * 题目63:股票的最大利润;
 * */
#include <iostream>
#include <vector>

using namespace std;

int maxPro(const int* numbers, int len)
{
    if(numbers == nullptr || len < 2)
        return 0;
    int minValue = numbers[0];
    int maxPro = numbers[1]-numbers[0];

    for(int i=2; i<len; i++)
    {
        if(numbers[i-1] < minValue)
            minValue = numbers[i-1];  // minValue保存的是前i-1个数的最小值
        if((numbers[i] - minValue) > maxPro)
            maxPro = numbers[i] - minValue;
    }
    return maxPro;
}


int main()
{
    int x[] = {9,11,8,5,7, 12, 16,14};
    int* p = x;
    cout << maxPro(p, 8);
    return 0;
}

