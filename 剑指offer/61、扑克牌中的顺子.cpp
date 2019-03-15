class Solution {
public:
    bool IsContinuous( vector<int> numbers )
    {
        // 数组排序
        int len = numbers.size();
        if(len<1) return false;
        sort(numbers.begin(), numbers.end());
        // 统计为０的个数
        int zero = 0;
        int small = 0;
        for(int i=0; i<len;i++)
        {
            if(numbers[i] == 0)
                zero++;
            else
            {
                small = i;
                break;
            }
        }
        // 统计空缺的个数，注意相邻元素相同的返回false
        int vac = 0;
        int big = small + 1;
        for(; big<len; big++)
        {
            if(numbers[small] == numbers[big])
                return false;
            vac += numbers[big]-numbers[small]-1;
            small = big;
        }
        return (zero>=vac)?true:false;
    }
};
