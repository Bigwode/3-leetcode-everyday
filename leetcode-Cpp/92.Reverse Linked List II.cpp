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
    ListNode* reverseBetween(ListNode* head, int m, int n)  // 注意题目要求只能循环一次就得实现题目要求
    {
        if(!head || !head->next || n-m==0) return head;
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;  // 防止首节点改变
        n -= m;
        
        ListNode* pre = dummy;
        
        while(--m)
            pre = pre->next;
        
        ListNode* cur = pre->next;
        ListNode* move = nullptr;
        
        while(n--)  // 这里可以理解为将cur->next(move)节点移动到pre->next，cur节点指向的节点其实每次是不变的。
        {
            move = cur->next;
            cur->next = move->next;
            move->next = pre->next;
            pre->next = move;
        }
        
        return dummy->next;
        
    }
};
