class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
            sum += nums[i];
        if(sum%2==1) return false;  // 和为奇数
        
        sum /= 2;
        
        vector<bool> dp(sum+1, false);  // dp[i]表示原数组是否可以取出若干数字，使得其和为i
        dp[0] = true;
        
        for(auto num : nums)
        {
            for(int i=sum; i>=num; --i)
            {
                dp[i] = dp[i] || dp[i-num];  // 当之前就已经是true了，那么只需要保持true就可以了，或者是之前的是满足i-num的，然后
            }
        }
        
        return dp[sum];
    }
};
