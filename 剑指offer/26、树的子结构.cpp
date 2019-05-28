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
    bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2)  // 递归判断是不是子树
    {
        if(pRoot2 == nullptr) return true;  // 如果子树为空
        if(pRoot1 == nullptr) return false;  // 如果子树不为空，但是大树为空
        if(pRoot1->val != pRoot2->val)  // 
            return false;
        else
            return isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right);  // 如果左子树和右子树都相同
    }
     
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)　　// 递归遍历一棵树
    {
        bool result = false;
        if(pRoot1!=nullptr && pRoot2!=nullptr)  // 循环条件
        {
            if(pRoot1->val == pRoot2->val)  // 先找值相同的根节点
                result = isSubtree(pRoot1, pRoot2);  // 找到相同的根节点，然后判断是否是子树
            if(!result)
                result = HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);  // 如果不是子树，递归查找左子树和右子树
        }
        return result;
        
    }
};
