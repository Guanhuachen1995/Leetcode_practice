class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<int> res(hits.size(), 0);
        int n = grid.size(), m = grid[0].size();
        for(auto h:hits) {
            grid[h[0]][h[1]]--;
        }
        
        for(int i = 0; i < m; i++)
            DFS(grid, 0 ,i);
        
        for(int i = hits.size() - 1; i >= 0; i--) {
            int x = hits[i][0], y = hits[i][1];
            grid[x][y]++;
            if(grid[x][y] == 1 && connect(grid, x, y))
                res[i] = DFS(grid, x, y) - 1;
        }
        return res;
        
    }
    
    bool connect(vector<vector<int>>& grid, int i, int j) {
        if(i == 0)   return true;
        vector<vector<int>> dir{{1,0}, {-1, 0}, {0,1}, {0, -1}};
        for(auto d:dir) {
            int x = i+d[0], y = j+d[1];
            if( x>=0 && x < grid.size() && y>=0 && y < grid[0].size() && grid[x][y] == 2)   return true;
        }
        return false;
    }
    
    int DFS(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1)
            return 0;
        vector<vector<int>> dir{{1,0}, {-1, 0}, {0,1}, {0, -1}};
        int res = 1;
        grid[i][j] = 2;
        for(auto d:dir) {
            res += DFS(grid, i + d[0], j + d[1]);
        }
        return res;
    }
};
