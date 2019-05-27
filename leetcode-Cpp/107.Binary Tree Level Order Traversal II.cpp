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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        // use queue to do level-traverse
        vector<vector<int>> v;
        levelOrder(root, v, 0);
        
        // reverse output's order
        reverse(v.begin(), v.end());
        return v;
    }
    
    void levelOrder(TreeNode* root, vector<vector<int>> &v, int curlevel)
    {
        if (root==NULL) return;
        if(v.empty() || curlevel > v.size()-1) v.push_back(vector<int>());
        v[curlevel].push_back(root->val);
        levelOrder(root->left, v, curlevel+1);
        levelOrder(root->right, v, curlevel+1);
    }
};
