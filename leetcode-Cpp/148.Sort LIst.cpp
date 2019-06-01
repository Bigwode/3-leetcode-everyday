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
    ListNode* merge(ListNode* head1, ListNode* head2)  //合并两个排序的链表
    {
        if(!head1) return head2;
        if(!head2) return head1;
        
        ListNode* res, *p;
        
        if(head1->val <= head2->val)
        {
            res = head1;
            head1 = head1->next;
        }
        else{
            res = head2;
            head2 = head2->next;
        }
        
        p = res;
        
        while(head1 && head2)
        {
            if(head1->val <= head2->val)
            {
                p->next = head1;
                head1 = head1->next;
            }
            else
            {
                p->next = head2;
                head2 = head2->next;
            }
            p = p->next;
        }
        
        if(head1)
            p->next = head1;
        
        if(head2)
            p->next = head2;
        
        return res;
    }
    
    ListNode* sortList(ListNode* head)
    {
        // 设置快慢指针将链表分成两部分
        if(!head || !head->next) return head;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(!fast->next && !fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        fast = slow->next;
        slow->next = nullptr;
        
        head = sortList(head);
        fast = sortList(fast);
        
        return merge(head, fast);
            
    }
};
