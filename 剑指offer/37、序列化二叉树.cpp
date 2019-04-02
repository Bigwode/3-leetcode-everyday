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
    void serialize(TreeNode* root, string& str)
    {
        if (root == nullptr)
        {
            str += "$,";  //叶子结点的左右子结点为空则用 $ 来代替
            return;
        }
        str += to_string(root->val);  //将结点值（int）转换成字符串（string）类型
        str += ',';
        serialize(root->left, str);  //递归序列化结点的左子树
        serialize(root->right, str);  //递归序列化结点的右子树
    }
    
    char* Serialize(TreeNode* root)
    {
        if (root == nullptr)
            return nullptr;
        string str;
        serialize(root, str);
        char* buffer = new char[str.size()];
        for(int i=0; i<str.size(); i++)
        {
            *(buffer+i) = str[i];
        }
        // *(buffer+str.size()) = '\0'; // 默认会在末尾加上'\0'
        return buffer;
    }
    
    TreeNode* deserialize(char** str)
    {
        if (**str == '$')
        {
            (*str) += 2;
            return nullptr;
        }
        int val = 0;
        while (**str != ',' && **str != '\0')  //把字符串类型的数字转换成int类型的数字
        {
            val = val * 10 + (**str - '0');
            ++(*str);
        }
        TreeNode* root = new TreeNode(val);  //构建根结点
        if (**str == '\0')
            return root;
        else
            ++(*str);
        root->left = deserialize(str);  //递归的构建左子树结点
        root->right = deserialize(str);  //递归的构建右子树结点
        return root;
    }

    TreeNode* Deserialize(char* str)
    {
        if (str == nullptr)
            return nullptr;
        return deserialize(&str);
    }
};
