class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map <int, int> m;
        vector<int> res; 
        for(int i : nums1)
            m[i]++;
        for(int j : nums2)
        {
            m[j]--;
            if (m[j] >= 0) res.push_back(j);
        }
        
        return res;
        
    }
};
