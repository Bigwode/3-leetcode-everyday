class Solution {
public:
    int mySqrt(int x) 
    {
        if (x == 0 || x == 1)
            return x;
        int low = 1, high = x/2, mid;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if((mid+1) > x/(mid+1) && x/mid >= mid) return mid;
            else if(x/mid < mid) high = mid-1;
            else low = mid + 1;
        }
        return mid;
    }
};
