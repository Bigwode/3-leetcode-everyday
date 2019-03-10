class Solution {
public:
    void Permutation(string str, int begin, vector<string>& res)
    {
        if(begin == str.length())
        {
            res.push_back(str);  //　
            return;
        }
        for(int i=begin; str[i] != '\0'; i++)
        {
            if(i != begin && str[i] == str[begin])  //　重复的字符跳过，不交换位置
                continue;
            swap(str[i], str[begin]);
            Permutation(str, begin+1, res);  //　从下一个开始
            swap(str[i], str[begin]);
        }
    }
    
    vector<string> Permutation(string str)
    {
        vector<string> res;
        if(str.length() == 0) return res;
        Permutation(str, 0, res);
        sort(res.begin(), res.end());  // 
        return res;
    }
};
