class Solution {
public:
    bool IsBalanced(TreeNode *root, int & dep){
        if(root == nullptr){
            return true;
        }
        int left = 0;
        int right = 0;
        if(IsBalanced(root->left,left) && IsBalanced(root->right, right))
        {
            int dif = left - right;
            if(dif>=-1 && dif <=1)
            {
                dep = ((left > right) ? left : right) + 1;
                return true;
            }
        }
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int dep = 0;
        return IsBalanced(pRoot, dep);
    }
};
