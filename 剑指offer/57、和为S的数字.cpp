class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum)
    {
        vector<int> res;
        int len = array.size();
        if (len < 1) return res;
        int i=0,j=len-1;
        while(i<j)
        {
            if(array[i]+array[j] == sum)
            {
                res.push_back(array[i]);
                res.push_back(array[j]);
                return res;
            }
            else if(array[i]+array[j] > sum)
                j--;
            else
                i++;
        }
        return res;
    }
};
