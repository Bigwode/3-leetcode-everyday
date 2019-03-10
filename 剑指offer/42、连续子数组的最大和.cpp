class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        int len = array.size();
        if(len <= 0) return 0;
        int curSum = array[0];
        int maxSum = array[0];
        
        for(int i=1; i<len; i++)
        {
            if(curSum <= 0)
                curSum = array[i];
            else
                curSum += array[i];
            if(curSum > maxSum)
                maxSum = curSum;
        }
        return maxSum;
    }
};
