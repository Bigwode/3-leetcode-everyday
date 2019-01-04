#include <iostream>
#include <vector>

using namespace std;


void bubble_sort(vector<int>& num)
{
    for (int i=0; i<num.size()-1; i++)
    {
        for (int j=0; j<num.size()-1-i; j++)
        {
            if (num[j] > num[j+1])
            {
                int temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }
}

int main ( )
{
    vector<int>s = {7,1,5,3,6,4};
    bubble_sort(s);

    return 0;
}
