class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int id = 0;
        while(id < nums.size())
        {
            if (nums[id] == val)
            {
                nums[id] = nums.back();
                nums.pop_back();
            }
            else id += 1;
        }
        return nums.size();
    }
};
