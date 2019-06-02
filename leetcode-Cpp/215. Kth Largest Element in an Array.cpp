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
    int partition(vector<int>& nums, int low, int high)
    {
        int dummy = nums[low];
        while(low<high)
        {
            while(low<high && nums[high]<=dummy) high--;
            nums[low] = nums[high];
            while(low<high && nums[low]>=dummy) low++;
            nums[high] = nums[low];
        }
        nums[low] = dummy;
        return low;
    }
    
    int findKthLargest(vector<int>& nums, int k)
    {
        int len = nums.size();
        int low = 0;
        int high = len-1;
        int pivot = partition(nums, low, high);
        
        while(pivot != k-1)
        {
            if(pivot < k-1)
            {
                low = pivot+1;
                pivot = partition(nums, low, high);
            }
            else
            {
                high = pivot-1;
                pivot = partition(nums, low, high);
            }
        }
        
        return nums[pivot];
    }
};

