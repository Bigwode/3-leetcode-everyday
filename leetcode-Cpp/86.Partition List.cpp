/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* p = new ListNode(-1);
        ListNode* pHead = p;
        ListNode* q = new ListNode(-1);
        ListNode* qHead = q;
        
        while(head)
        {
            if (head->val < x)
            {
                p->next = head;
                p = p->next;
            }
            else
            {
                q->next = head;
                q = q->next;
            }
            head = head->next;
        }
        q->next = NULL; //重要
        p->next = qHead->next;
        return pHead->next;
    }
};
