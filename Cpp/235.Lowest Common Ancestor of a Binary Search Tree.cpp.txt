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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        int rootVal = root->val;
        int pVal = p->val;
        int qVal = q->val;
        if(pVal > rootVal && qVal > rootVal)
            return lowestCommonAncestor(root->right, p, q);
        else if (pVal < rootVal && qVal < rootVal)
            return lowestCommonAncestor(root->left, p, q);
        else
            return root;
    }
};