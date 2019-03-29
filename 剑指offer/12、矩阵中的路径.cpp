class Solution {
public:
    bool isThis(const char* matrix, int rows, int cols, int row, int col, const char* str, vector<bool>& isVisited, int& loc)
    {
        if(str[loc] == '\0') return true;  // 如果当前节点是字符串的结束符
        bool path = false;
        if(row>=0 && row<rows && col>=0 && col<cols && matrix[row*cols+col] == str[loc] && isVisited[row*cols+col] == 0)
        {  // 如果当前节点在字符串中并且没有被访问过，且不超出矩阵边界
            ++loc;  // 被访问过的字符数+1
            isVisited[row*cols+col] = 1;  // 访问过
            path = isThis(matrix, rows, cols, row-1, col, str, isVisited, loc) ||   // 如果这个节点的上下左右节点存在有字符串中的元素
                   isThis(matrix, rows, cols, row+1, col, str, isVisited, loc) || 
                   isThis(matrix, rows, cols, row, col-1, str, isVisited, loc) || 
                   isThis(matrix, rows, cols, row, col+1, str, isVisited, loc);
            if(!path)  // 如果当前节点的上下左右没有存在于字符串中的元素，(注意这里是在判断里面)
            {
                --loc;  // 回退一个
                isVisited[row*cols+col] = 0; // 退出的元素被标记为未被访问
            }
        }
        return path;
    }
    
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
            return false;
        vector<bool> isVisited(rows*cols, 0);  // 记录是否访问过某个节点
        int loc = 0;  // 记录访问到字符的位置
        for(int row=0; row<rows; row++)
        {
            for(int col=0; col<cols; col++)
            {
                if(isThis(matrix, rows, cols, row, col, str, isVisited, loc)) return true;  //当前节点是否满足在字符串
            }
        }
        return false;
    }


};
