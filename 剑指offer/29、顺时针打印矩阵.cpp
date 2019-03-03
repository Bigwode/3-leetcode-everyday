class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) 
    {
        vector<int> res;
		int col, row;
		row=matrix.size();     // matrix.size()表示矩阵的逻辑结构中的行数 
		if(row==0) return res;		
		col=matrix[0].size();
 
		int circle=((row<col?row:col)-1)/2+1; // 圈数 
		
		for(int k=0; k<circle; k++)  // 此处k是所在圈数，最外圈是第0圈
		{
			for(int i=k; i<col-k; i++) res.push_back(matrix[k][i]);  // 从左到右，横坐标(列数)i++
			for(int j=k+1; j<row-k; j++) res.push_back(matrix[j][col-1-k]);  // matrix[k+1][j] ==> matrix[row-k][j]; 从上到下，纵坐标(当前所在行数)j++
			for(int m=col-k-2; (m>=k)&&(row-k-1!=k); m--) res.push_back(matrix[row-k-1][m]); // 防止重复, 从右到左，横坐标(当前所在列数)i--
			for(int n=row-k-2; (n>k)&&(col-k-1!=k); n--) res.push_back(matrix[n][k]);  // 防止重复，从下到上，纵坐标(当前所在行数)n--
		}		
	    return res;	
    }
};
