class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int count =0, mid =0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if (grid[i][j] == 1)
                {
                    count++;
                    if(i!=0 && grid[i-1][j]==1) mid++;
                    if(j!=0 && grid[i][j-1]==1) mid++;
                }       
            }
        }
        return count*4-mid*2;
    }
};
