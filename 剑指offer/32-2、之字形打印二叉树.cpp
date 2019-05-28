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
        if(pRoot==nullptr) return out;
        stack<TreeNode*> s[2];
        int cur = 0;  // 既然是用了两个栈，空间复杂度要高于上一个题，所以我们就不用统计下一层的节点数了，直接push进栈就好了
        int next = 1;
        s[cur].push(pRoot);
        while(!s[0].empty() || !s[1].empty())
        {
            TreeNode* temp = s[cur].top();
            res.push_back(temp->val);
            s[cur].pop();
            if(cur==0)  // 奇数层，先左后右
            {
                if(temp->left)
                    s[next].push(temp->left);
                if(temp->right)
                    s[next].push(temp->right);
            }
            else　　// 偶数层，先右后左
            {
                if(temp->right)
                    s[next].push(temp->right);
                if(temp->left)
                    s[next].push(temp->left);
            }
            if(s[cur].empty())
            {
                out.push_back(res);
                res.clear();
                cur = 1-cur;
                next= 1-next;
            }
        }
        return out;
    }
};

/******************************************************************8888/
/*麻烦版，直接思路*/

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
        if(pRoot==nullptr) return out;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(pRoot);
        int cur = 1;
        int next = 0;
        while(!s1.empty() || !s2.empty())
        {
            while(!s1.empty())
            {
                res.push_back(s1.top()->val);
                if(s1.top()->left) // s1是奇数层，先左后右
                {
                    s2.push(s1.top()->left);
                    next++;
                }
                if(s1.top()->right)
                {
                    s2.push(s1.top()->right);
                    next++;
                }
                s1.pop();
                cur--;
                if(cur==0)
                {
                    out.push_back(res);
                    res.clear();
                    cur = next;
                    next = 0;
                }
            }
            while(!s2.empty())
            {
                res.push_back(s2.top()->val);
                if(s2.top()->right)  //　s2是偶数层，先右后左。
                {
                    s1.push(s2.top()->right);
                    next++;
                }
                if(s2.top()->left)
                {
                    s1.push(s2.top()->left);
                    next++;
                }
                s2.pop();
                cur--;
                if(cur==0)
                {
                    out.push_back(res);
                    res.clear();
                    cur = next;
                    next = 0;
                }
            }
        }
        return out;
    }
};
