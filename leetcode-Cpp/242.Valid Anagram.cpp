/*判断两个字符串是不是由相同的一组字符构成的*/
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size() != t.size()) return false;
        int count[26] = {0};
        for(int i=0; i<s.size(); i++)
        {
            count[s[i]-'a'] ++;
            count[t[i]-'a'] --;
        }
        for(int j=0;j<26;j++)
        {
            if(count[j]) return false;
        }
        return true;
    }
};

