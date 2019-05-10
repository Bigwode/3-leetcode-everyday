/*
剑指offer-47 礼物的最大值
*/
#include<iostream>
#include <vector>

using namespace std;

int getMaxValue(const int* values, int rows, int cols)
{
    if (values == nullptr || rows <= 0 || cols <= 0)
        return 0;
    int** maxValues = new int* [rows];
    for(int i=0; i<rows; i++)
    {
        maxValues[i] = new int[cols];
    }

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            int left = 0;
            int top  = 0;
            if(i>0)
                top = maxValues[i-1][j];
            if(j>0)
                left = maxValues[i][j-1];
            maxValues[i][j] = max(top, left) + values[i*cols+j];
        }
    }

    int maxValue = maxValues[rows-1][cols-1];
    for(int i=0;i<rows; i++)
        delete[] maxValues[i];
    return maxValue;
}

int main()
{
    int *test = new int[16];
    test[0] = 1;
    test[1] = 10;
    test[2] = 3;
    test[3] = 100;
    test[4] = 12;
    test[5] = 2;
    test[6] = 9;
    test[7] = 6;
    test[8] = 5;
    test[9] = 7;
    test[10] = 4;
    test[11] = 11;
    test[12] = 3;
    test[13] = 7;
    test[14] = 16;
    test[15] = 5;

    cout << getMaxValue(test,4,4) << endl;

    return 0;
}

/*空间优化，即只使用一个一维数组存储*/
int getMaxValue(const int* values, int rows, int cols)
{
    if (values == nullptr || rows <= 0 || cols <= 0)
        return 0;
    int* maxValues = new int[cols];

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            int left = 0;
            int top  = 0;
            if(i>0)
                top = maxValues[j];  
            if(j>0)
                left = maxValues[j-1];
            maxValues[j] = max(top, left) + values[i*cols+j];
        }
    }

    int maxValue = maxValues[cols-1];
    delete[] maxValues;
    return maxValue;
}



