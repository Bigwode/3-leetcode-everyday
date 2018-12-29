class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        if(num == 0 || num == 1) return true;
        int low = 2, high = num/2;
        while(low <= high)
        {
            long mid = low + (high-low)/2;
            if (mid*mid == num) return true;
            else if (mid*mid > num) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
};
