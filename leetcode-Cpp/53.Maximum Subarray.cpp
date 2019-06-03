class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int curSum = nums[0];
        int maxSum = nums[0];
        int len = nums.size();
        
        for(int i=1;i<len;i++)
        {
            if(curSum < 0)
                curSum = nums[i];
            else
                curSum += nums[i];
            if(curSum > maxSum)
                maxSum = curSum;
        }
        return maxSum;
    }
};
