class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int len = nums.size();
        int target = 0;
        for(int i=0; i<len; i++)
            target += nums[i];
        if(target % 2 == 1) return false;
        target /= 2;
        
        bool dp[target+1];
        memset(dp, false, sizeof(dp));
        
        dp[0] = true;
        
        for(auto num : nums)
        {
            for(int j=target; j>=num; j--)
            {
                dp[j] = dp[j] || dp[j-num];   
// 如果当之前就已经是true了，那么只需要保持true就可以了，或者是之前的是满足i-num的，
// dp[j]表示原数组是否可以取出若干个数字，其和为j
            }
        }
        return dp[target];
    }
};
