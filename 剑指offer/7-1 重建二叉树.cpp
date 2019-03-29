// https://blog.csdn.net/hellozmz/article/details/53331851
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        int len = vin.size();
        if(len == 0) return nullptr;  // 结束条件
        vector<int> pre_left, pre_right;
        vector<int> vin_left, vin_right;
        TreeNode* p = new TreeNode(pre[0]);
        
        int index = 0;
        for(int i=0; i<len; i++)  // 找出在vin中pre的第一个元素出现的位置，用来划分左子树和右子树
        {
            if(vin[i] == pre[0])
            {
                index = i;
                break;
            }
        }
        
        for(int i=0; i<index; i++)  // 左子树的前序和中序
        {
            pre_left.push_back(pre[i+1]);
            vin_left.push_back(vin[i]);
        }
        for(int i=index+1; i<len; i++)  // 右子树的前序和中序
        {
            pre_right.push_back(pre[i]);
            vin_right.push_back(vin[i]);
        }
        
        p->left = reConstructBinaryTree(pre_left, vin_left);  // 递归左子树
        p->right = reConstructBinaryTree(pre_right, vin_right);  // 递归右子树
        
        return p;
    }
};
