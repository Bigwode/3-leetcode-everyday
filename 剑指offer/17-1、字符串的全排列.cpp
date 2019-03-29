/*
 * 全排列递归写法,例如(A,B,C,D)的全排列是A后跟(B,C,D)的全排列；B后跟....,没有考虑重复元素的情况
 * Author:David
 * */
#include <iostream>
using namespace std;

template<typename T>
void permutation(T array[], int begin, int end)
{
    int i;

    if(begin == end) // 只有一个元素，排列完成
    {
        for(i = 0; i <= end; ++i)
            cout<<array[i]<<" ";
        cout<<endl;
        return;
    }
    else
    {
        for(i = begin; i <= end; ++i)
        {
            swap(array[i], array[begin]);  // 确定第一个位置上的元素
            permutation(array, begin + 1, end);  //　确定下一个位置的元素
            swap(array[i], array[begin]); 
        }
    }
}

int main(int argc, char **argv)
{
    int a[4] = {1, 2, 3, 4};
    permutation(a, 0, 3);

    return 0;
}

