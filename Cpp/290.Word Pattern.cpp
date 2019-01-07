class Solution {
public:
    bool wordPattern(string pattern, string str) 
    {
        istringstream strcin(str);
        string s;
        vector<string> v;
        while(strcin >> s) v.push_back(s);
        if (pattern.size() != v.size()) return false;
        unordered_map<char, string> m;
        for (int i = 0; i < pattern.size(); ++i) {
            if(m.count(pattern[i]))
            {
                if(m[pattern[i]] != v[i]) return false;
            }
            else
                {
                    for (auto count : m)
                        if (count.second == v[i]) return false;
                    m[pattern[i]] = v[i];
                }
        }
        return true;    
    }
};
