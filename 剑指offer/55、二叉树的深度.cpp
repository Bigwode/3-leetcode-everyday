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
        
        return (l<r)?(r+1):(l+1);  // 既有左子树又有右子树，那么二叉树的深度就是左右子树深度最大值加１
    }
};
