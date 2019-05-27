class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int len = triangle.size();
        vector<int> minPath(triangle.back());
        for(int i=len-2; i>=0; i--)
        {
            for(int j=0; j<=i; j++)
            {
                minPath[j] = min(minPath[j], minPath[j+1])+triangle[i][j];
            }
        }
        return minPath[0];
    }
};
