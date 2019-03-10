/*思路１：类似于快速排序，找到index=k的时候前k个数即为最小的ｋ个数*/
class Solution {
public:
    int Partition(vector<int>& input, int low, int high)
    {
        int dummy = input[low];
        while(low < high)
        {
            while(low < high && input[high]>=dummy) high--;
            input[low] = input[high];
            while(low < high && input[low]<=dummy) low++;
            input[high] = input[low];
        }
        input[high] = dummy;
        return high;
    }
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> res;
        if(input.size() == 0 || k<=0 || k>input.size()) return res;
        int low = 0;
        int high = input.size()-1;
        int index= Partition(input, low, high);
        if(index != k-1)
        {
            if(index > k-1)
                index = Partition(input, low, high-1);
            else
                index = Partition(input, low+1, high);
        }
        
        for(int i=0; i<k; i++)
            res.push_back(input[i]);
        return res;
    }
};
