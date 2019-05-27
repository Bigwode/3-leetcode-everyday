/*方法1：递归*/
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if (nums.size()>0)
            return rob(nums, nums.size()-1);
        else
            return 0;
    }
    int rob(vector<int>& nums, int i)
    {
        if (i== 0) return nums[0];
        else if (i==1) return max(nums[0], nums[1]);
        else
        {
            return max(rob(nums, i-2)+nums[i], rob(nums, i-1));
        }
    }
};

/*方法2，记忆式搜索 4ms, faster than 46.57%*/
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if (nums.size()>0)
        {
            vector<int> pro(nums.size(),0);
            pro[0] = nums[0];
            pro[1] = max(nums[0], nums[1]);
            for(int i=2;i<nums.size();i++)
                pro[i] = max(pro[i-1], pro[i-2]+nums[i]);
            return pro.back();
        }
        else
            return 0;
    }
};
