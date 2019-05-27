class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        vector<int>s1(256, -1);
        vector<int>s2(256, -1);
        int len = s.size();
        for(int i=0; i<len; i++)
        {
            if(s1[s[i]] != s2[t[i]]) return false;
            else
            {
                s1[s[i]] = i;
                s2[t[i]] = i;
            }
        }
        return true;
    }
};
