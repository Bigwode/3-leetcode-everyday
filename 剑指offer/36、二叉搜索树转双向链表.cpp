/******************************Method 1******************************/
class Solution {
public:
    
    TreeNode* Convert(TreeNode* root)
    {
        if(root==NULL)  return NULL;//递归边界
        if(root->left==NULL && root->right==NULL)  return root;//递归边界
        
        TreeNode* left = Convert(root->left);//递归左边
        TreeNode* p = left;
        while(p!=NULL && p->right!=NULL)//找左子树最右节点
            p = p->right;//当p->right为NULL的时候跳出循环
        if(left)//若左子树不空
        {
            p->right = root;
            root->left = p;
        }
        TreeNode* right = Convert(root->right);//递归右边
        if(right)//若右子树不空
        {
            root->right = right;
            right->left = root;
        }
        return left ? left : root;
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
