#include <iostream>
#include <vector>

using namespace std;

void InsertSort(vector<int>& num)
{
    for(int i=0;i<num.size();i++)
    {
        int cur = num[i];
        int j = i-1;
        while(j>=0 && num[j] > cur)
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

