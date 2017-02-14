class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > path(m, vector<int>(n, grid[0][0]));
        for(int i=1; i< n; i++)
        {
            path[0][i]=grid[0][i]+path[0][i-1];
        }
        for(int i=1; i< m; i++)
        {
            path[i][0]=grid[i][0]+path[i-1][0];
        }
        for (int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(path[i-1][j]<path[i][j-1])
                {
                    path[i][j]= grid[i][j]+ path[i-1][j];
                }
                else{
                    path[i][j] = grid[i][j] + path[i][j-1];
                }
            }
        }
        return path[m-1][n-1];
    }
};
