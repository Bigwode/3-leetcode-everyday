#include <iostream>
#include <stack>
#include <queue>

using namespace std;

//struct TreeNode
//{
//    int val;
//    struct TreeNode *left, *right;
//};

struct TreeNode
{
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    explicit TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};


//前序
void PreOrder(TreeNode *t)
{
    if (t != nullptr)
    {
        cout << t->val << endl;
        PreOrder(t->left);
        PreOrder(t->right);
    }
}
//中序
void Inorder(TreeNode *t)
{
    if (t != nullptr)
    {
        Inorder(t->left);
        cout << t->val << endl;
        Inorder(t->right);
    }
}
//后序
void PostOrder(TreeNode *t)
{
    if (t != nullptr)
    {
        PostOrder(t->left);
        PostOrder(t->right);
        cout << t->val << endl;
    }
}
//前序非递归
void PreOrder2(TreeNode *t)
{
    stack<TreeNode *> s;
    TreeNode *p = t;


    while (p != nullptr || !s.empty())
    {
        if (p != nullptr)
        {
            cout << p->val << endl;//根
            s.push(p);
            p = p->left;//左
        }
        else
        {
            p = s.top();
            p = p->right;//右
            s.pop();
        }
    }
}


//中序非递归
//使用递归的方法，依次把树的左子树进行保存，然后依次回退完成根的访问，最后访问右子树
void Inorder2(TreeNode *t)
{
    stack<TreeNode*> s;
    TreeNode *p = t;


    while (p != nullptr || !s.empty())
    {
        if (p != nullptr)
        {
            s.push(p);
            p = p->left;//左
        }
        else
        {
            p = s.top();
            cout << p->val << endl;//根·
            s.pop();
            p = p->right;//右
        }
    }
}

//后序非递归
void PostOrder2(TreeNode *t)
{
    stack<TreeNode *> s;
    TreeNode *p = t;
    TreeNode *tmp = nullptr;
    //tmp 指针是为了保存节点上一次访问的状态


    while (p != nullptr || !s.empty())
    {
        if (p != nullptr)
        {
            s.push(p);
            p = p->left;//左
        }
        else
        {
            //每次取栈定元素
            //判断栈顶元素的右孩子是否为空，
            //如果不为空，查看之前访问的节点是不是该栈顶元素的右孩子
            p = s.top();
            if (p->right != nullptr && p->right != tmp)
            {
                p = p->right;//右
            }
            else
            {
                cout << p->val << endl;//根
                s.pop();
                //每次访问节点之后，需要将缓存上一次访问的节点，并且将指针置空
                tmp = p;
                p = nullptr;
            }
        }
    }


}

//层次遍历
void LevelOrder(TreeNode *t)
{
    queue<TreeNode *> q;
    TreeNode *p;
    q.push(t);


    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << p->val << endl;
        if (p->left != nullptr)
            q.push(p->left);
        if (p->right != nullptr)
            q.push(p->right);
    }
}

//遍历是二叉树各种操作的基础
//1、已知树求结点的双亲结点：使用前、中、后序遍历
//2、求结点的孩子结点：使用前、中、后序遍历
//3、求二叉树的深度：使用层次遍历
//4、求二叉树的叶子结点个数：使用层次遍历
//5、判断两颗二叉树是否相同：依次遍历每个节点进行比较


int main()
{
    TreeNode t4(4),t5(5),t6(6), t7(7);
    TreeNode t2(2, &t4, &t5);
    TreeNode t3(3, &t6, &t7);
    TreeNode t1(1, &t2, &t3);

    LevelOrder(&t1);

    return 0;
}






