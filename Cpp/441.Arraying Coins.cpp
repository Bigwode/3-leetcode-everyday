class Solution {
public:
    int arrangeCoins(int n) 
    {
        // return int(sqrt(2*long(n)+0.25)-0.5);  AC 32ms
        if(n==1||n==0) return n;
        int low = 1, high = n;
        while(low<high)
        {
            long mid = low+(high-low)/2;
            if (mid*(mid+1)/2 > n) high = mid;
            else low = mid+1;
        }
        return low-1;
    }
};
