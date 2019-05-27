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
    bool isSymmetric(TreeNode* root) 
    {
        if(!root) return true;
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* l, TreeNode* r)
    {
        if(!l && !r) return true;
        if(!l || !r) return false;
        if(l->val == r->val)
            return (isMirror(l->left, r->right) && isMirror(r->left, l->right));
        else
            return false;
    }
};
