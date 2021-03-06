/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Solution 1 using recursively.
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if (head == NULL || head->next == NULL) return head;
        ListNode* res = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return res;
    }
};
// Solution 2 using iteratively.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* pre = NULL;
        ListNode* cur = NULL;
        while(head)
        {
            cur = head;
            head = head->next;
            cur->next = pre;  //只要是改变指针都会影响到head的，所以head要先移动。
            pre = cur;
        }
        return cur;
    }
};
