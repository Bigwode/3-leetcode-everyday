class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int len = prices.size(), pro=0, max=0;
        for (int i=1; i<len; i++)
        {
            pro += prices[i]-prices[i-1];
            if (pro>max) max = pro;
            if (pro<0) pro =0;
        }
        return max;
    }
};
