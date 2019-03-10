class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if(numbers.size() == 0)
        return 0;
        int res = numbers[0];
        int count = 1;
        for(int i=1; i<numbers.size(); i++)
        {
            if(count == 0)
            {
                res = numbers[i];
                count = 1;
            }
            if(numbers[i] == res)
                count += 1;
            else
                count -= 1;
        }
        int num = 0;
        for(int j=0; j<numbers.size(); j++)  //　注意判断这个数字出现的次数是否超过数组长度的一半。
        {
            if(numbers[j] == res)
                ++num;
        }
        if(num > numbers.size()/2)
            return res;
        else
            return 0;
    }
};
