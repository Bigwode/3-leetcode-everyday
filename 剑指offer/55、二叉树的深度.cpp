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
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot) return 0;
        int l = TreeDepth(pRoot->left);
        int r = TreeDepth(pRoot->right);
        
        return (l<r)?(r+1):(l+1);
    }
};
