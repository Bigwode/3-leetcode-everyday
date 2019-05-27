/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return sortedArrayToBST(nums, 0, nums.size());
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) 
    {
        if(start>=end) return NULL;
        int mid = start+(end-start)/2;
        TreeNode* p = new TreeNode(nums[mid]);
        p->left = sortedArrayToBST(nums, start, mid);
        p->right = sortedArrayToBST(nums, mid+1, end);
        return p;
    }
    
};
