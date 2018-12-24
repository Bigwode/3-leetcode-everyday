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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = head, *pre = dummy;
        
        while(cur && cur->next)
        {
            if (cur->val != cur->next->val)
            {
                pre = cur;
                cur = cur->next;
            }
            else
            {
                while(cur->next && cur->val == cur->next->val)
                {
                    cur = cur->next;
                }
                pre->next = cur->next;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
