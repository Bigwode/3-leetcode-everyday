#include<hash_set>
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int len = nums.size();
        return len*(len+1)/2-sum;
    }
};
