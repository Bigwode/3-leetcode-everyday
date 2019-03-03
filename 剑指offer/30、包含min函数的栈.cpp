class Solution {
public:
    stack<int> s;
    stack<int> s_min;
    void push(int value)
    {
        s.push(value);
        if(s_min.size()==0 || value<=s_min.top())
            s_min.push(value);
        else
            s_min.push(s_min.top());
    }
    void pop()
    {
        s.pop();
        s_min.pop();
    }
    int top()
    {
        return s.top();
    }
    int min()
    {
        return s_min.top();
    }

};
