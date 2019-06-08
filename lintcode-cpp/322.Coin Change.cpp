class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount+1, amount+1);  // 最大不会超过amount
        dp[0] = 0;
    
        for(auto coin : coins)
        {
            for(int i=1; i<=amount; i++)
            {
                if(coin <= i)
                    dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        return (dp[amount] > amount) ? -1: dp[amount];
    }
};
