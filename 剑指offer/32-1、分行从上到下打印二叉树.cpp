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
        vector<vector<int> > Print(TreeNode* pRoot)
        {
            vector<int> res;
            vector<vector<int>> out;
            queue<TreeNode*> q;
            if(pRoot==nullptr) return out;
            q.push(pRoot);
            int next = 0;  // 表示下一层节点的个数
            int cur = 1;  // 表示当前层节点的个数
            while(!q.empty())
            {
                TreeNode* temp = q.front();
                res.push_back(temp->val);
                if(temp->left)
                {
                    q.push(temp->left);
                    next++;
                }
                if(temp->right)
                {
                    q.push(temp->right);
                    next++;
                }
                q.pop();　　// 弹出一个，当前层节点数数减１
                cur--;
                if(cur==0)
                {
                    out.push_back(res);
                    res.clear();
                    cur= next;　　// 当前层处理完之后，重置当前层和下一层节点数。
                    next = 0;
                }
            }
            return out;
        }
    
};
