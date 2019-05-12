/*Method 2:*/
class Solution {
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    
    void Insert(int num)
    {
        // 偶数放在最大堆，奇数放在最小堆，每次需要交换最大队和最小堆的堆顶的值
        if(((max_heap.size()+min_heap.size()) & 1) == 0)  // 这里不要忘记(),易出错
            max_heap.push(num);
        else
            min_heap.push(num);
        if(min_heap.size() > 0 && max_heap.size() > 0)  // 每次交换，保证最小堆的值比最大堆的值要大。
        {
            int temp = min_heap.top();
            min_heap.pop();
            max_heap.push(temp);

            temp = max_heap.top();
            max_heap.pop();
            min_heap.push(temp);
        }
    }

    double GetMedian()
    {
        if(((max_heap.size()+min_heap.size()) & 1) == 0)
            return (max_heap.top() + min_heap.top()) / 2.0;
        else
            return max_heap.top();
    }

};

/*Method 1:剑指offer解题方案：最大堆+最小堆（奇数，偶数）*/
class Solution {
public:
    vector<int> min;
    vector<int> max;
    void Insert(int num)
    {
        if(((min.size() + max.size()) & 1) == 0)  // 偶数是插入最小堆
        {
            if(max.size()>0 && max[0]>num)  // 但是插入的数比最大堆的最大值小
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
            if(min.size()>0 && min[0]<num)  // 但是插入的数比最大堆的最大值小
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
