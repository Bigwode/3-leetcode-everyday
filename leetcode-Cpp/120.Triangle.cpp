class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int len = triangle.size();
        vector<int> minPath(triangle.back()); //
        for(int i=len-2; i>=0; i--)  // 相当于从倒数第二行往上计算
        {
            for(int j=0; j<=i; j++)  //
            {
                minPath[j] = min(minPath[j], minPath[j+1])+triangle[i][j];
            }
        }
        return minPath[0];
    }
};
