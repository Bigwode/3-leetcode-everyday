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
    int depth(TreeNode* root)
    {
        if (root==NULL) return 0;
        return max(depth(root->left), depth(root->right))+1;
    }
    bool isBalanced(TreeNode* root) 
    {
        if (root==NULL) return true;
        int l = depth(root->left);
        int r = depth(root->right);
        return abs(l - r)<2  && isBalanced( root->left) && isBalanced(root->right);
    }
};
