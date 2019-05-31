/*思路1：最小堆解法，时间复杂度O(nlogk)*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto i:nums)
        {
            if(q.size() < k)
                q.push(i);
            else if (i > q.top())
            {
                q.pop();
                q.push(i);
            }
        }
        return q.top();
        
    }
};

/*思路2*/
class Solution {
public:
    int partition(vector<int>& nums, int start, int end)
    {
        int dummy = nums[start];
        while(start < end)
        {
            while(start<end && nums[end]<=dummy) end--;
            nums[start] = nums[end];
            
            while(start<end && nums[start]>=dummy) start++;
            nums[end] = nums[start];
        }
        nums[end] = dummy;
        return end;
    }
    
    int findKthLargest(vector<int>& nums, int k) 
    {
        int len = nums.size();
        int start = 0;
        int end = len-1;
        int inds = partition(nums, start, end);
        
        while(inds != k-1)
        {
            if(inds < k-1)
                inds = partition(nums, inds+1, end);
            else
                inds = partition(nums, start, inds-1);
        }
        
        return nums[inds];
    }
};
