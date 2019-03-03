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
            while(i!= len && pushV[i] != popV[j])
            {
                s.push(pushV[i++]);
            }
            while(i!= len && pushV[i] == popV[j])
            {
                ++i;
                ++j;
            }
        }
        while(s.empty() == 0 && s.top() == popV[j])
        {
            s.pop();
            ++j;
        }
        if(j == len)
            return true;

        return false;
    }
};
