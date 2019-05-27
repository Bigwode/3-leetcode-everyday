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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0), *p = &head;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int num = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = num/10;
            p->next = new ListNode(num % 10);
            p = p->next;
            l1 = (l1 ? l1->next : l1);
            l2 = (l2 ? l2->next : l2);
        }
        return head.next;
    }
};
