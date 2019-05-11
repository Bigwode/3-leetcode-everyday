/*直接插入排序*/
#include <iostream>
#include <vector>

using namespace std;

void InsertSort(vector<int>& num)
{
    for(int i=1;i<num.size();i++)
    {
        int cur = num[i];
        int j = i-1;
        while(j>=0 && num[j] > cur)  // 前面大的值往后移，将当前值插入
        {
            num[j+1] = num[j];
            j--;
        }
        num[j+1] = cur;
    }

    for (int m=0; m<num.size();m++)
    {
        cout<<num[m]<<endl;
    }
}


int main ( )
{
    vector<int>s = {7,1,5,3,6,4};
    InsertSort(s);

    return 0;
}

