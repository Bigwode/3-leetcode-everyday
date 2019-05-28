/*思路１：类似于快速排序，找到index=k的时候前k个数即为最小的ｋ个数*/
class Solution {
public:
    int Partition(vector<int>& num, int low, int high)
    {
        int len = num.size();
        int dummy = num[low];
        while(low < high)
        {
            while(low< high && num[high]>=dummy) high--;
            num[low] = num[high];
            while(low< high && num[low]<=dummy) low++;
            num[high] = num[low];
        }
        num[low] = dummy;
        return low;
    }
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> res;
        int len = input.size();
        if(len == 0 || k<=0 || k>len) return res;　　//必须判断
        int low =0;
        int high = len-1;
        int ind = Partition(input, low, high);

        while(ind != k-1)
        {
            
            if(ind<k-1)
                ind = Partition(input, ind+1, high);
            else
                ind = Partition(input, low, ind-1);
        }
        
        for (int i=0; i<k;i++)
        {
            res.push_back(input[i]);
        }
        return res;
    }
};
        for(int i=0; i<k; i++)
            res.push_back(input[i]);
        return res;
    }
};
