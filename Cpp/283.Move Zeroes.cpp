class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int len = nums.size(), j=0;
        for(int i=0; i<len; i++)
        { 
            if(nums[i] != 0) nums[j++] = nums[i];
        }
        for(;j<len;j++)
            nums[j] = 0;
    }
};
