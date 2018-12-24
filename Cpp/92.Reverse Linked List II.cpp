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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        if (m == n) return head;
        n -= m;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        
        while(--m)
        {
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        while(n--)
        {
            ListNode* move = cur->next;
            cur->next  = move->next;
            move->next = pre->next;
            pre->next  = move;
        }
        return dummy->next;
    }
};
