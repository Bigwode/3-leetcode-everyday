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
            if(pNode != nullptr)  //
                return pNode;
            count++;
            if(count == k)
                return pRoot;
            pNode = KthNode(pRoot->right, k);
            if(pNode != nullptr)  //
                return pNode;
        }
        return nullptr;
    }
};
