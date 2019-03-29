class Solution
{
public:
    void push(int node) {
        stack1.push(node);  // push的时候往1
    }

    int pop() {
        int res=0;
        if(stack2.empty())
        {
            while(!stack1.empty()) // pop的时候，先把所有的1 pop到2里
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            res = stack2.top(); // 然后从2里pop
            stack2.pop();
        }
        else{
            res = stack2.top();
            stack2.pop();
        }
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
