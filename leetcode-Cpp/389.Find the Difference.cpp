class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        char res=0;
        for(char i:s) res ^= i;
        for(char j:t) res ^= j;
        return res;
//         unordered_map<char, int> m;
//         for(int i=0; i<s.size(); i++)
//         {
//             m[s[i]]++;
//             m[t[i]]--;
//         }
//         m[t.back()]--;
        
//         for(auto res : m)
//         {
//             if(res.second == -1) return res.first;
//         }
    }
};
