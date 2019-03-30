class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV)
    {
        stack<int> s;
        int i = 0;
        int j = 0;
        int len = pushV.size();

        while(i!= len)
        {
            while(i!= len && pushV[i] != popV[j])  // 没遇到相等的，意味着还没有出栈
            {
                s.push(pushV[i++]);
            }
            while(i!= len && pushV[i] == popV[j])  // 遇到相等的，就不用入栈了
            {
                ++i;
                ++j;
            }
        }
        while(s.empty() == 0 && s.top() == popV[j])  // 所有元素入栈结束，开始按照顺序出栈
        {
            s.pop();
            ++j;
        }
        if(j == len) // 判断是否出栈完毕
            return true;

        return false;
    }
};
