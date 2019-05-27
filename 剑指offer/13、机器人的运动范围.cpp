class Solution {
public:
    int noLargerTarget(int target)  // 求一个整数各个位数的数值之和
    {
        int sum = 0;
        while(target>0)
        {
            sum += target%10;
            target /= 10;
        }
        return sum;
    }
    
    bool check(int threshold, int rows, int cols, int row, int col, vector<bool>& isVisited)
    {  // 判断是否可以访问(row, col)位置, 即是否可以该位置上的各位数之和不大于threshold
        if(row>=0 && row<rows && col>=0 && col<cols && 
           (noLargerTarget(row)+noLargerTarget(col))<=threshold && 
           !isVisited[row*cols+col])
            return true;
        return false;
    }
    
    int moving(int threshold, int rows, int cols, int row, int col, vector<bool>& isVisited)
    {
        int count = 0;
        if(check(threshold, rows, cols, row, col, isVisited))　　// 如果可以访问该位置
        {
            isVisited[row*cols+col] = 1;
            count = 1 + moving(threshold, rows, cols, row-1, col, isVisited)
                      + moving(threshold, rows, cols, row+1, col, isVisited)
                      + moving(threshold, rows, cols, row, col-1, isVisited)
                      + moving(threshold, rows, cols, row, col+1, isVisited);
        }
        return count;
    }
    
    int movingCount(int threshold, int rows, int cols)
    {
        vector<bool> isVisited(rows*cols, 0);
        int count = moving(threshold, rows, cols, 0, 0, isVisited);  // 和上一个题目不一样的是，这里规定是从(0,0)点开始。
        return count;
    }
};
