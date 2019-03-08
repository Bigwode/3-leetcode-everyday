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
    void ConvertToList(TreeNode* pNode, TreeNode** pLastNodeinList)
    {
        if(pNode == nullptr)
            return;
        TreeNode* pCurrent = pNode;
        if(pCurrent->left != nullptr)  //　左
            ConvertToList(pCurrent->left, pLastNodeinList);
        
        pCurrent->left = *pLastNodeinList;  //　根
        if(*pLastNodeinList != nullptr)
            (*pLastNodeinList)->right = pCurrent;
        *pLastNodeinList = pCurrent;
        
        if(pCurrent->right != nullptr)  //　右
            ConvertToList(pCurrent->right, pLastNodeinList);
    }
    
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* pLastNodeinList = nullptr;  // 指向双向链表的尾节点
        ConvertToList(pRootOfTree, &pLastNodeinList);
        
        TreeNode* pHead = pLastNodeinList;
        while(pHead != nullptr && pHead->left != nullptr)
            pHead = pHead->left; // 返回双向链表的头结点
        return pHead;
    }
};
