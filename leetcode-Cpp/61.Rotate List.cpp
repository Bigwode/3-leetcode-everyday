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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head) return head;
        ListNode* tail  = head;
        int len = 1;
        while(tail->next)
        {
            tail = tail->next;
            len++;
        }
        tail->next = head;
        int i;
        for (i=0;i<len-k%len;i++)
        {
            tail = tail->next;
        }
        head = tail->next;
        tail->next = NULL;
        return head;
        
    }
};
