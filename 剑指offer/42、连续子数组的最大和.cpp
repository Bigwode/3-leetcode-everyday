class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        int len = array.size();
        if(len <= 0) return 0;
        int curSum = array[0];  // 当前和
        int maxSum = array[0];  // 当前最大值
        
        for(int i=1; i<len; i++)
        {
            if(curSum <= 0)  // 如果当前和小于0，更新为当前值
                curSum = array[i];
            else
                curSum += array[i];  // 否则累加
            if(curSum > maxSum)  //更新最大值
                maxSum = curSum;
        }
        return maxSum;
    }
};
