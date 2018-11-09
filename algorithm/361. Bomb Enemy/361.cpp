class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0)  return 0;
        int n = grid[0].size();
        if(n == 0)  return 0;
        vector<vector<int>> up(m, vector<int>(n)), down(m, vector<int>(n)), left(m, vector<int>(n)), right(m, vector<int>(n));
        
        
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j++) {
                up[i][j] = 0;
                if(grid[i][j] != 'W') {
                    if(grid[i][j] == 'E')
                        up[i][j] = 1;
                    if(i > 0)
                        up[i][j] += up[i-1][j];
                }
            }
        }
        
        for(int i = m - 1; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                down[i][j] = 0;
                if(grid[i][j] != 'W') {
                    if(grid[i][j] == 'E')
                        down[i][j] = 1; 
                    if(i < m - 1)
                        down[i][j] += down[i+1][j];
                }
            }
        }
        
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j++) {
                left[i][j] = 0;
                if(grid[i][j] != 'W') {
                    if(grid[i][j] == 'E')
                        left[i][j] = 1;
                    if(j > 0)
                        left[i][j] += left[i][j-1];
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = n-1; j >= 0; j--) {
                right[i][j] = 0;
                if(grid[i][j] != 'W') {
                    if(grid[i][j] == 'E')
                        right[i][j] = 1; 
                    if(j < n-1)
                        right[i][j] += right[i][j+1];
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '0') {
                    int temp = up[i][j] + down[i][j] + left[i][j] + right[i][j];
                    res = max(res, temp);
                }
                
            }
        }
        return res;
    }
};
