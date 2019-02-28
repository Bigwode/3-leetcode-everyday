/*
方法1：非递归实现
*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==nullptr)
            return pHead2;
        if(pHead2==nullptr)
            return pHead1;
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        ListNode* result = new ListNode(-1);
        ListNode* out = result;
        while(p1!=nullptr && p2!=nullptr)
        {
            if(p1->val <= p2->val)
            {
                result->next = p1;
                result = result->next;
                p1 = p1->next;
            }
            else
            {
                result->next = p2;
                result = result->next;
                p2 = p2->next;
            }
        }
        if(p1==nullptr)
            result->next = p2;
            result = result->next;
        if(p2==nullptr)
            result->next = p1;
            result = result->next;
        return out->next;
    }
};

/*
方法2：递归实现
*/

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==nullptr)
            return pHead2;
        if(pHead2==nullptr)
            return pHead1;
        ListNode* result = nullptr;
        if(pHead1->val <= pHead2->val)
        {
            result = pHead1;
            result->next = Merge(pHead1->next, pHead2);
        }
        if(pHead1->val > pHead2->val)
        {
            result = pHead2;
            result->next = Merge(pHead1, pHead2->next);
        }
        return result;
    }
};

