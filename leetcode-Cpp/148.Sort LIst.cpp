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
    ListNode* merge(ListNode* left, ListNode* right)  // 相当于合并两个排序链表
    {
        if(!left) return right;
        if(!right) return left;
        
        ListNode* res, * p;
        if(left->val <= right->val)
        {
            res = left;
            left = left->next;
        }
        else
        {
            res = right;
            right = right->next;
        }
        p = res;  // 
        
        while(left && right)
        {
            if(left->val <= right->val)
            {
                p->next = left;
                left = left->next;
            }
            else
            {
                p->next = right;
                right = right->next;
            }
            p = p->next;  // 这句放在括弧外更简洁
        }
        
        if(left)
            p->next = left;
        if(right)
            p->next = right;
        
        return res;
    }
    
    ListNode* sortList(ListNode* head)
    {
        // 先设置快慢指针将链表分割成两部分
        if(!head || !head->next) return head;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        fast = slow->next;
        slow->next = nullptr;
        
        ListNode* left = sortList(head);
        ListNode* right = sortList(fast);
        
        return merge(left, right);
    }
};
