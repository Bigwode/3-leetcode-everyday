class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum)
    {
        int low = 1;
        int high = 2;
        vector<vector<int> > res;
        vector<int> r = {1,2};
        int SumofVector = 3;
        while(low<(sum+1)/2)
        {
            if(SumofVector == sum)
            {
                res.push_back(r);
                high++;
                r.push_back(high);
                SumofVector += high;
            }
            else if(SumofVector < sum)
            {
                high++;
                r.push_back(high);
                SumofVector += high;
            }
            else
            {
                low++;
                SumofVector -= r[0];
                r.erase(r.begin());
            }
        }
        return res;
    }
};
