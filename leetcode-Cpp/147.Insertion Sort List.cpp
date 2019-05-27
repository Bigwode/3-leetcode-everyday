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
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;  // 防止头结点发生改变
        
        ListNode* pre = dummy, *cur = head;
        
        while(cur)  // cur指向的是已经排好序的链表的末尾节点
        {
            if(cur->next && cur->next->val < cur->val)  // 新元素是cur->next；它要和已经排好序的链表的末尾元素cur的值进行比较
            {
                while(pre->next && pre->next->val < cur->next->val)  // 从头开始找到第一个不小的节点
                    pre = pre->next;
                ListNode* temp = pre->next;  // 保存这个节点
                pre->next = cur->next;  // 链表节点的插入
                cur->next = cur->next->next;
                pre->next->next = temp;
                pre = dummy;  // 重置pre为链表首
            }
            else
                cur = cur->next;  // 如果后一个元素比最大值要大，直接后移一个位置就可以
        }
        return dummy->next;
        
    }
};
