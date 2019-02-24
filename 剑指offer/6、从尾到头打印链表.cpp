/*
显式调用栈实现
*/
# include<stack>
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) 
    {
        stack<int> stack;
        vector<int> vector;
        ListNode *p = head;
        while(p != nullptr)
        {
            stack.push(p->val);
            p = p->next;
        }
        while(!stack.empty()) 
        {
            vector.push_back(stack.top());
            stack.pop();
        }
        return vector;
    }
};


/*************************递归实现1*******************/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> vec;
    vector<int> printListFromTailToHead(ListNode* head)
    {
        if (head != nullptr)
        {
            if(head->next != nullptr)
                printListFromTailToHead(head->next);
            vec.push_back(head->val);
        }
        return vec;
    }
};

/*************************递归实现2*******************/
class Solution {
public:
    vector<int> vec;
    vector<int> printListFromTailToHead(ListNode* head)
    {

        if(head == nullptr)
            return vec;
        printListFromTailToHead(head->next);
        vec.push_back(head->val);
        return vec;
    }
};
