/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        while (head != NULL && head->val == val) // 先找到第一个不为某值的节点
        {
            head = head->next;
        }
        if (head == NULL) return head;
        ListNode* dummy = head;
        
        while (dummy->next != NULL)
        {
            if (dummy->next->val == val)
            {
                dummy->next = dummy->next->next;
            }
            else
            {
                dummy = dummy->next;
            }
        }
        return head;
    }
};
