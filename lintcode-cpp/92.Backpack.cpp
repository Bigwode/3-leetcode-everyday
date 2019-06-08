/*
未优化空间版本
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
    // write your code here
    int len = A.size();
    int dp[len][m+1];  // 这里最好是和背包重量对应起来，所以多加了一列  可以直接={0},这样编译器会将未初始化的部分全部补0
    memset(dp, 0, sizeof(dp));

    for(int i=0; i<=m; i++)  // 第一行边界条件
        dp[0][i] = (A[0] <= i)? A[0]: 0;

    for(int i=1; i<len; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(A[i] <= j)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i]]+A[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[len-1][m];
}
};


//------------------------------------------------------------
int backPack(int m, vector<int> &A) {
    // write your code here
    int len = A.size();
    int dp[len+1][m+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=len; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(A[i-1] <= j)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i-1]]+A[i-1]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[len][m];
}
/*
优化空间版本
*/
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
    // write your code here
    int len = A.size();
    int dp[m+1] = {0};

    for(int i=0; i<len; i++)  // 注意这里此时要从0开始
    {
        for(int j=m; j>=A[i]; j--)
            dp[j] = max(dp[j], dp[j-A[i]]+A[i]);
    }

    return dp[m];
}
};

