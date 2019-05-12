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
    int sumOfLeftLeaves(TreeNode* root, bool l)
    {
        if(!root) return 0;
        if(!root->left && !root->right)
            return l ? root->val:0;
        return sumOfLeftLeaves(root->left, true)+sumOfLeftLeaves(root->right, false);   
    }
    
    int sumOfLeftLeaves(TreeNode* root) 
    {
        return sumOfLeftLeaves(root, false);
    }
};