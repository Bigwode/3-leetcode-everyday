class Solution {
public:
    int countPrimes(int n) 
    {
        vector<bool> check(n, true);
        check[0] = false;
        check[1] = false;
        
        for(int i=2;i*i<n;i++)
        {
            if (check[i] == true)
            {
                for(int j=i*i;j<n;j+=i)
                    {
                        check[j]=false;
                    }
            }
        }
        return count(check.begin(), check.end(), 1);
    }
};
