/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root)
    {
        queue<TreeNode*> q;
        vector<int> res;
        if(root == nullptr)
            return res;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            res.push_back(temp->val);
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        return res;
    }
};
