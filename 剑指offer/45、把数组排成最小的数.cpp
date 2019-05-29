class Solution {
public:
    static bool cmp(int a, int b)
    {
        string A = to_string(a)+to_string(b);
        string B = to_string(b)+to_string(a);
        return A < B;
    }
    string PrintMinNumber(vector<int> numbers)
    {
        int len = numbers.size();
        if(len == 0)
            return "";
        string res;
        sort(numbers.begin(), numbers.end(), cmp);  // 按照cmp规则排序,时间复杂度O(nlogn)，基于快排或者插入排序
        for(int i=0; i<len; i++)
            res += to_string(numbers[i]);
        return res;
    }
};
