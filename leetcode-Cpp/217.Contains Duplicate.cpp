class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        int k = nums.size();
        set<int> s(nums.begin(), nums.end());
        int m = s.size();
        return !(k==m);
    }
};
