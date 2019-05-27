/*p爬到第n层的最小代价*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int len = cost.size();
        vector<int> num(len+1, 0);
        num[0] = 0;
        num[1] = 0;
        for(int i=2;i<=len;i++)
        {
            num[i] = min(num[i-1]+cost[i-1],num[i-2]+cost[i-2]);
        }
        return num.back();
    }
};

/*爬过第n层的最小代价*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int len = cost.size();
        vector<int> num(len, 0);
        num[0] = cost[0];
        num[1] = cost[1];
        for(int i=2;i<len;i++)
        {
            num[i] = cost[i]+min(num[i-1],num[i-2]);
        }
        return min(num[len-1], num[len-2]);
    }
};


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int len = cost.size();
        // vector<int> num(len, 0);
        int a = cost[0];
        int b = cost[1];
        int c = 0;
        for(int i=2;i<len;i++)
        {
            c = cost[i]+min(a,b);
            a = b;
            b = c;
        }
        return min(a,b);
    }
};
