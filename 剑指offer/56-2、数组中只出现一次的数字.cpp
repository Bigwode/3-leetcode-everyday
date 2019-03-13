#include <iostream>
#include <vector>

using namespace std;

int FindNumberAppearingOnce(int numbers[], int length)
{
    int bitSum[32] = {0};
    for(int i=0; i<length; i++)
    {
        int bitMask = 1;
        for(int j=31; j>=0; j--)
        {
            int bit = numbers[i] & bitMask;
            if(bit)
                bitSum[j]++;
            bitMask = bitMask << 1;
        }
    }

    int result = 0;
    for(int i=0; i<32;i++)
    {
        result = result<<1;
        result += bitSum[i]%3;
    }
    return result;
}


int main()
{
    cout << (1<<1) ;
    return 0;
}

