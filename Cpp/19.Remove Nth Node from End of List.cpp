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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        // Method 1
        // ListNode* p = new ListNode(0);
        // ListNode* slow = p;
        // ListNode* fast = p;
        // p->next = head;
        // int i;
        // for (i=1;i<=n;i++)
        // {
        //     fast = fast->next;
        // }
        // while(fast && fast->next)
        // {
        //     fast = fast->next;
        //     slow = slow->next;
        // }
        // slow->next = slow->next->next;
        // return p->next;
        
        //Method 2
        ListNode** slow = &head;
        ListNode* fast = head;
        int i;
        for (i=1;i<n;i++)
        {
            fast = fast->next;
        }
        while(fast && fast->next)
        {
            fast = fast->next;
            slow = &((*slow)->next);
        }
        (*slow) = (*slow)->next;
        return head;
        
    }
};
