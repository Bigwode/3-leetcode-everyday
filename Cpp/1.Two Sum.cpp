class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> m;
        vector<int> res;
        int len = nums.size();
        
        for(int i=0; i<len; i++)
        {
            int cur = nums[i];
            if(m.count(cur))
            {
                res.push_back(m[cur]);
                res.push_back(i);
            }
            else m[target-cur] = i;
        }
        return res;
    }
};
