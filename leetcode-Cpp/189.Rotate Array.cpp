class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        k = k%nums.size();
        // Method 1 20ms faster than 59.92%
        nums.insert(nums.begin(), nums.end()-k, nums.end());
        nums.erase(nums.end()-k, nums.end());
        // Method 2
        while(k>0)
        {
            int left = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), left);
            k--;
        }
    }
};
