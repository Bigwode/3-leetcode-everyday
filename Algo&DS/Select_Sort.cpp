#include <iostream>
#include <vector>

using namespace std;

void SelectSort(vector<int>& num)
{
    for(int i=0;i<num.size();i++)
    {
        int min = i;
        for(int j=i+1;j<num.size();j++)
        {
            if (num[j]<num[min]) min = j;
        }
        //将num[min]和num[i-1]进行交换
        int temp = num[i];
        num[i] = num[min];
        num[min] = temp;
    }

    for (int m=0; m<num.size();m++)
    {
        cout<<num[m]<<endl;
    }
}


int main ( )
{
    vector<int>s = {2,1,5,3,6,4};
    SelectSort(s);

    return 0;
}

