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
    int Partition(vector<int>& num, int low, int high)
    {
        int dummy = num[low];
        while(low<high)
        {
            while (low<high && num[high]<=dummy)  --high;  // 将大的数放到前面
            num[low] = num[high];
            while (low<high && num[low]>=dummy)  ++low;
            num[high] = num[low];
        }
        num[high] = dummy;
        return high;
    }
    
    int findKthLargest(vector<int>& nums, int k)
    {
        int high = nums.size()-1;
        int low  = 0;
        while(low < high)
        {
            int pivot = Partition(nums, low, high);
            if(pivot == k-1) return nums[pivot];
            else if(pivot < k-1) // 在右半部分
                low = pivot+1;
            else  // 在左半部分
                high = pivot-1;
        }
        return nums[low]; // 当只有一个元素的时候
    }
};
