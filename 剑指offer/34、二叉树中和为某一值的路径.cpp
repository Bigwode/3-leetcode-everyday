/*
 * 题目17：打印从1到n的最大的n位数
 * */

#include <iostream>
#include <vector>

using namespace std;



struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void Find(TreeNode* root,int expectNumber, vector<vector<int>>& res, vector<int>& path)
{
    if(!root) return;
    path.push_back(root->val);  // 将当前节点的值加到当前路径中
    expectNumber = expectNumber - (root->val);
    if (!root->left && !root->right && expectNumber == 0)  // 如果到达叶子节点并且路径之和相等
        res.push_back(path);
    else
    {
        if(root->left != nullptr)
            Find(root->left, expectNumber, res, path);
        if(root->right != nullptr)
            Find(root->right, expectNumber, res, path);
    }
    // expectNumber -= path.back(); 这里传的是值，不影响上一层的值。
    path.pop_back(); // 到达叶子节点并且不满足和的要求，退出一个值。
}

vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
    vector<vector<int>> res;
    vector<int> path;  // 记录当前路径
    Find(root, expectNumber, res, path);
    return res;
}

int main()
{
    TreeNode t1 = TreeNode(10);
    TreeNode t2 = TreeNode(5);
    TreeNode t3 = TreeNode(4);
    TreeNode t4 = TreeNode(7);
    TreeNode t5 = TreeNode(12);

    t5.left = nullptr;
    t5.right = nullptr;

    t3.left = nullptr;
    t3.right = nullptr;

    t4.left = nullptr;
    t4.right = nullptr;

    t2.left = &t3;
    t2.right = &t4;

    t1.left = &t2;
    t1.right = &t5;

    vector<vector<int>> res;
    res = FindPath(&t1, 22);
    for (int i =0; i<res.size(); i++)
    {
        for(int j=0; j<res[i].size(); j++)
        {
            cout << res[i][j] << endl;
        }
        cout << "---" << endl;
    }

}

