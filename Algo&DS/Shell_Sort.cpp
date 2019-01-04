/*希尔排序，可能存在问题*/
#include <iostream>
#include <vector>

using namespace std;

void InsertSort(vector<int>& num, int stride)
{
    for(int i=1;i<num.size();i++)
    {
        int cur = num[i];
        int j = i-stride;
        while(j>=0 && num[j] > cur)
        {
            num[j+stride] = num[j];
            j = j-stride;
        }
        num[j+stride] = cur;
    }
}

void Shell_Sort(vector<int>& num, vector<int>& strides)
{
    for(int i=0; i<strides.size();i++)
    {
        InsertSort(num, strides[i]);
    }
}
int main ( )
{
    vector<int>nums = {7,5,3,6,4,2,1};
    vector<int>s = {5,3,1};
    Shell_Sort(nums, s);


    for (int m=0; m<nums.size();m++)
    {
        cout<<nums[m]<<endl;
    }

    return 0;
}

