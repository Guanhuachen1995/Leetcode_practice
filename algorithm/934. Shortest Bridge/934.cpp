class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int n  = A.size();
        int m = A[0].size();
        int color = 2;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 1) {
                    paint(A, i, j, color++);
                    //cout<<A[i][j]<<endl;
                }
            }
        }
        for(int col = 3; ;col++) {
            for(int i = 0; i < A.size(); i++) {
                for(int j = 0; j < m; j++) {
                    if(A[i][j] == col) {
                        if (expand(A, i - 1, j, col) || expand(A, i, j - 1, col) || 
                            expand(A, i + 1, j, col) || expand(A, i, j + 1, col)) return col - 3;
                    }
                }
            }
        }
    }
    
    
    bool expand(vector<vector<int>>& A, int i, int j, int cl) {
        if (i < 0 || j < 0 || i == A.size() || j == A[0].size()) return false;
        if (A[i][j] == 0) A[i][j] = cl + 1;
        return A[i][j] == 2;
    }
    
    void paint(vector<vector<int>>& grid, int i, int j, int color) {
        vector<pair<int,int>> dir{{1,0}, {-1, 0}, {0,1}, {0,-1}};
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = color;
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(auto d:dir) {
                if(x+d.first >= 0 && x+d.first < grid.size() && y+d.second >= 0 && y+d.second < grid[0].size() && grid[x+d.first][y+d.second] == 1) {
                    grid[x+d.first][y+d.second] = color;
                    q.push({x+d.first, y+d.second});
                }
                    
                
            }
        }
    }
};
