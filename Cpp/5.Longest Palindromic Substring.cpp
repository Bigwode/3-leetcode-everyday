class Solution {
public:
    string longestPalindrome(string s) 
    {
        if(s.size() < 2) return s;
        int right = 0, left = 0, len = 0;
        vector<vector<int> > dp(s.size(), vector<int> (s.size(), 0));
        for(int i=0; i<s.size(); i++)
        {
            dp[i][i] = 1;
            for(int j=0; j<i; j++)
            {
                if( (s[i]==s[j]) && ((i-j<2) || (dp[j+1][i-1])) )
                {
                    dp[j][i] = 1;
                    if(len < i-j+1)
                    {
                        len = i-j+1;
                        left = j;
                        right = i;
                    }
                }
            }
        }
        return s.substr(left, right-left+1);
        
    }
};
