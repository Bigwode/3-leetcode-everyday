/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    int count = 0;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot != nullptr)
        {
            TreeNode* pNode = KthNode(pRoot->left, k);
            if(pNode != nullptr)  //这里为什么加这个判断？
                return pNode;
            count++;
            if(count == k)
                return pRoot;　//　这里为什么返回的是pRoot?
            pNode = KthNode(pRoot->right, k);
            if(pNode != nullptr)
                return pNode;
        }
        return nullptr;
    }
};
