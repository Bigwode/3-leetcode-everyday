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
    void dfs(TreeNode* root, string s, vector<string>& result)
    {
        if(!root->left && !root->right){
            result.push_back(s);
        }
        if(root->left) dfs(root->left, s+"->"+to_string(root->left->val), result);
        if(root->right) dfs(root->right, s+"->"+to_string(root->right->val), result);
    }
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> result;
        if(!root) return result;
        dfs(root, to_string(root->val), result);
        return result;
    }
};