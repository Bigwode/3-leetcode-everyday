class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> sv(26, 0), pv(26, 0), res;
        for(int i=0; i<p.size(); i++)
        {
            sv[s[i]-'a']++;
            pv[p[i]-'a']++;
        }
        if (sv==pv) res.push_back(0);
        
        for(int i=p.size(); i< s.size(); i++)
        {
            sv[s[i]-'a']++;
            sv[s[i-p.size()]-'a']--;
            if(sv == pv) res.push_back(i-p.size()+1);
        }
        
        return res;
    }
};
