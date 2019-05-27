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
    ListNode* swapPairs(ListNode* head) 
    {
        //Method 1
//         if (!head || !(head->next))
//         {
//             return head;
//         }
//         ListNode* p = head->next;
//         head->next = swapPairs(p->next);
//         p->next = head;
        
//         return p;
        
        // Method 2
        if (!head || !(head->next))
        {
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* node = dummy;
        while(head && head->next)
        {
            ListNode* p = head->next;
            head->next = p->next;
            p->next = head;
            node->next = p;
            node = head;
            head = node->next;
        }
        return dummy->next;
    }
};
