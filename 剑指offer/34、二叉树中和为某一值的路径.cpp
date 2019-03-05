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

    void Find(TreeNode* root,int expectNumber, vector<vector<int>>& res, vector<int>& path)
    {
        if(!root) return;
        path.push_back(root->val);  // 将当前节点的值加到当前路径中
        expectNumber = expectNumber - (root->val);
        if (!root->left && !root->right && expectNumber == 0)
            res.push_back(path);
        else
        {
            if(root->left != nullptr)
                Find(root->left, expectNumber, res, path);
            if(root->right != nullptr)
                Find(root->right, expectNumber, res, path);
        }
        path.pop_back(); // 根节点并且不满足和的要求，退出一个值。
    }
    
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber)
    {
        vector<vector<int>> res;
        vector<int> path;  // 记录当前路径
        Find(root, expectNumber, res, path);
        return res;
    }
};
