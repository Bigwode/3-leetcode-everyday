class Solution {
public:
    int GetFirstK(vector<int>& data, int k, int start, int end)
    {
        int length = data.size();
        if(start > end)
            return -1;
        int middleIndex = start+(end-start)/2;
        int middleData = data[middleIndex];
        if(middleData==k)  // 中间的值为k
        {
            if((middleIndex>0 && data[middleIndex-1]<k) || middleIndex==0) //　如果是不位于首位置并且前一个值小于k　或者位于首位置
                return middleIndex;
            else
                end = middleIndex-1;
        }
        else if(middleData>k)
            end = middleIndex-1;
        else
            start = middleIndex+1;
        return GetFirstK(data, k, start, end);
    }

    int GetLastK(vector<int>& data, int k, int start, int end)
    {
        int length = data.size();
        if(start > end)
            return -1;
        int middleIndex = start+(end-start)/2;
        int middleData = data[middleIndex];
        if(middleData==k)
        {
            if((middleIndex<length-1 && data[middleIndex+1]>k) || middleIndex==length-1) // 如果不位于最后一个元素并且后一个值大于k 或者位于最后一个位置
                return middleIndex;
            else
                start = middleIndex+1;
        }
        else if(middleData<k)
            start = middleIndex+1;
        else
            end = middleIndex-1;
        return GetLastK(data, k, start, end);
    }
    
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int number = 0;
        int length = nums.size();
        vector<int> result = {-1,-1};
        
        if(length>0)
        {
            int first = GetFirstK(nums, target, 0, length-1);
            int last = GetLastK(nums, target, 0, length-1);
            
            result.clear();
            result.push_back(first);
            result.push_back(last);

        }
        return result;
    }
};
