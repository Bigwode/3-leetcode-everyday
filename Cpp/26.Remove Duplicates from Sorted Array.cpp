class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int count = 0, len = nums.size();
        for (int i=1; i<len; i++)
        {
            if(nums[i] == nums[i-1]) count += 1;
            else nums[i-count] = nums[i];
        }
        return len-count;
    }
};
