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
    bool isPalindrome(ListNode* head) 
    {
        if (head == NULL || head->next == NULL) return true;
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* secondHead = slow->next;
        ListNode* p1 = secondHead;
        ListNode* p2 = p1->next;
        slow->next = NULL;
        
        while(p1 != NULL && p2 != NULL)
        {
            ListNode* tmp = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = tmp;
        }
        secondHead->next = NULL;

        while(p1 != NULL)
        {
            if (p1->val != head->val) return false;
            p1 = p1->next;
            head = head->next;
        }
        return true;
    }
};
