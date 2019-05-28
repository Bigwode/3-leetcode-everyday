/******************************Method 1******************************/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree) return nullptr;
        if(!pRootOfTree->left && !pRootOfTree->right) return pRootOfTree;
        
        TreeNode* left = Convert(pRootOfTree->left);
        TreeNode* p = left;
        
        while(p && p->right)
            p = p->right;
        if (left)
        {
            p->right = pRootOfTree;
            pRootOfTree->left = p;
        }
        
        TreeNode* right = Convert(pRootOfTree->right);

        if(right)
        {
            right->left = pRootOfTree;
            pRootOfTree->right = right;
        }
        return left ? left : pRootOfTree;
    }
};
/******************************Method 2:剑指offer******************************/
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
        *pLastNodeinList = pCurrent;  // 最大节点
        
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
