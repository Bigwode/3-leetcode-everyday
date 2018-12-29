#include<set>
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        set<int> s(nums1.begin(), nums1.end());
        vector<int> res;
        for (int i : nums2)
        {
            if (s.erase(i)) res.push_back(i);
        }
        return res;
    }
};
