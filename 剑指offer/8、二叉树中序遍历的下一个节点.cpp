/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == nullptr)
            return nullptr;

        if(pNode->right != nullptr)  //如果有右子树，则找右子树的最左节点
        {
            pNode = pNode->right;
            while(pNode->left)
                pNode = pNode->left;
            return pNode;
        }
        while(pNode->next != nullptr)  //没右子树，则找第一个当前节点是父节点左孩子的节点
        {
            if(pNode->next->left == pNode)
                return pNode->next;
            pNode = pNode->next;
        }
        return nullptr;  //退到了根节点仍没找到，则返回null
    }
};
