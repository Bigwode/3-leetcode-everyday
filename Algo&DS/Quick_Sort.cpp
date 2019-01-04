#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int>& num, int low, int high)
{
    int dummy = num[low];
    //从最后搬一个小的数过来
    while (low<high && num[high]>=dummy)  --high;
    num[low] = num[high];
    // ++low;  //这时候肯定是要满足下边第一次循环的条件的。
    while (low<high && num[low]<=dummy)  ++low;
    num[high] = num[low];

    num[high] = dummy;
    return high;
}

void QSort(vector<int>& num, int low, int high)
{
    if(low<high)
    {
        //求中心点的值
        int pivot = Partition(num, low, high);
        QSort(num, low, pivot-1);
        QSort(num, pivot+1, high);
    }
}


int main ( )
{
    vector<int>s = {1,2,3,4,5,6};
    QSort(s, 0, s.size()-1);


    for (int m=0; m<s.size();m++)
    {
        cout<<s[m]<<endl;
    }

    return 0;
}

