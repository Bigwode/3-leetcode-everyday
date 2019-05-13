/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(!head) return nullptr;
        if(!head->next) return new TreeNode(head->val);  // 递归终止条件
        ListNode* pre, *slow, *fast=nullptr;
        slow = fast = head;

        while(fast && fast->next)  // 先找到中间位置的元素
        {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        pre->next = nullptr;  // 从slow前一个元素断开
        TreeNode* result = new TreeNode(slow->val);
        result->left = sortedListToBST(head); // 递归左右子树
        result->right = sortedListToBST(slow->next);
        
        return result;
    }
};
