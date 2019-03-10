class Solution {
public:
    vector<int> min;
    vector<int> max;
    void Insert(int num)
    {
        if(((min.size() + max.size()) & 1) == 0)  // 偶数是插入最小堆
        {
            if(max.size()>0 && max[0]>num)  // 插入的数比最大堆的最大值小
            {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());  // 插入最大堆
                num = max[0];
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<int>());  // 插入最小堆
        }
        else  // 奇数插入最大堆
        {
            if(min.size()>0 && min[0]<num)  // 插入的数比最大堆的最大值小
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());  // 插入最大堆
                num = min[0];
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }

    double GetMedian()
    { 
        int size = min.size()+max.size();
        if(size == 0) return 0.;
        double medium = 0.;
        if((size & 1) == 1)
            medium = min[0];
        else
            medium = (min[0]+max[0])/2.0;
        return medium;
    }

};
