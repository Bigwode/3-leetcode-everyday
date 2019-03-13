class Solution {
public:
    int GetFirstK(vector<int>& data, int k, int start, int end)
    {
        int length = data.size();
        if(start > end)
            return -1;
        int middleIndex = start+(end-start)/2;
        int middleData = data[middleIndex];
        if(middleData==k)
        {
            if((middleIndex>0 && data[middleIndex-1]<k) || middleIndex==0)
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
            if((middleIndex<length-1 && data[middleIndex+1]>k) || middleIndex==length-1)
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

    int GetNumberOfK(vector<int> data ,int k) {
        int number = 0;
        int length = data.size();
        if(length>0)
        {
            int first = GetFirstK(data, k, 0, length-1);
            int last = GetLastK(data, k, 0, length-1);
            if(first>-1 && last>-1)
                number = last-first+1;
        }
        return number;
    }
};
