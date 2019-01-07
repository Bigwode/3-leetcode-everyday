/*Method 1 需要遍历两遍*/
class Solution {
public:
    int firstUniqChar(string s) 
    {
        unordered_map<char, int>m;
        for(char i: s)
        {
            if (m.count(i)) m[i]++;
            else m[i]=1;
        }
        for(int j=0; j<s.size();j++)
        {
            if (m[s[j]] == 1) return j;
        }
        return -1;
    }
};
/*Method 1 放到256个vector中快一点*/
class Solution {
public:
    int firstUniqChar(string s)
    {
        vector<int> num_occurrences(256, 0);

        for (char &c : s) {
            ++num_occurrences[c];
        }

        for (int i = 0; i < s.size(); ++i) {
            if (num_occurrences[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }

};
