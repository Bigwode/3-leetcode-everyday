#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        unordered_map<int, int> m;
        vector<int> res;
        for(int i =0; i< len; i++)
        {
            if (m.count(numbers[i]))
            {
                res.push_back(m[numbers[i]]);
                res.push_back(i+1);
                return res;
            }
            else
            {
                m[target-numbers[i]] = i+1;
            }
        }

    }
};
