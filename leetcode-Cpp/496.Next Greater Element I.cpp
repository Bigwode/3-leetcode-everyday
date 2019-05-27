#include<stack>
#include<unordered_map>

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) 
    {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums)
        {
            while(s.empty() != 1 && s.top() < n)
            {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> res;
        for (int i : findNums) res.push_back(m.count(i) ? m[i] : -1);
        
        return res;
    }
};
