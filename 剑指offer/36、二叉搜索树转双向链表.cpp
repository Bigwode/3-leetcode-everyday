/******************************Method 1******************************/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree) return nullptr;
        if(!pRootOfTree->left && !pRootOfTree->right) return pRootOfTree;
        
        TreeNode* left = Convert(pRootOfTree->left);  // 将左子树构造成双向链表，返回双向链表的头结点
        TreeNode* p = left;
        
        while(p && p->right)　　// 找到左子树的最右节点
            p = p->right;
        if (left)  //　如果左子树不为空，将当前节点作为　(判断条件为p的时候效果一样)
        {
            p->right = pRootOfTree;
            pRootOfTree->left = p;
        }
        
        TreeNode* right = Convert(pRootOfTree->right);  // 将右子树构造成双向链表，返回双向链表的头结点

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
