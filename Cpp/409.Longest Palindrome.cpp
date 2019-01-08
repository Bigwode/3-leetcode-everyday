/*第一版代码，有多处需要优化*/
class Solution {
public:
    int longestPalindrome(string s) 
    {
        unordered_map<char, int> m;
        int odd = 0, even = 0;
        for(char i: s)
            m[i]++;
        for(auto j : m)
        {
            if(j.second%2==1) odd++;
            if(j.second > 1)
            {
                if(j.second%2==0) even += j.second;
                if(j.second%2==1) even += j.second-1;
            }
        }
        if (odd > 0) return even+1;
        else return even;
        
    }
};

/*改进之后，减少了不必要的步骤，4ms*/
class Solution {
public:
    int longestPalindrome(string s) 
    {
        unordered_map<char, int> m;
        int odd = 0;
        for(char i: s)
            m[i]++;
        for(auto j : m)
        {
            if(j.second%2==1) odd++;
        }
        return s.size()-odd+(odd>=1);
    }
};
