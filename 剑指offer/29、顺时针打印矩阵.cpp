class Solution {
public:
    void printMatrix(vector<vector<int> >matrix, int rows, int cols, int start, vector<int>& res)
    {
        int endX = cols-start-1;
        int endY = rows-start-1;

        for(int i=start;i<=endX; i++)　　// 从左到右
            res.push_back(matrix[start][i]);
        if(start<endY)  //　从上到下
        {
            for(int j=start+1;j<=endY;j++)
                res.push_back(matrix[j][endX]);
        }
        if(start<endX && start<endY)　 // 从右到左
        {
            for(int i=endX-1;i>=start;i--)
                res.push_back(matrix[endY][i]);
        }
        if(start<endX && start<endY-1)　　// 从下到上
        {
            for(int i=endY-1;i>=start+1;i--)
            {
                res.push_back(matrix[i][start]);
            }
        }
    }

    vector<int> printMatrix(vector<vector<int> > matrix)
    {
        vector<int> res;
        int rows=matrix.size();
        if(rows==0) return res;
        int cols=matrix[0].size();

        int start = 0;

        while(rows > start*2 && cols > start*2)  // 打印一圈的条件
        {
            printMatrix(matrix, rows, cols, start, res);
            ++start;
        }
        return res;
    }
};
