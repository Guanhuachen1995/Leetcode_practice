class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.size() == 0) return 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int res = 0, Max = INT_MIN;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!(i == 0|| i == m - 1 || j == 0 || j == n -1)) continue;
                que.push(pair<int,int>(heightMap[i][j], i*n + j));
                visited[i][j] = 1;
            }
        }
        vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        while(!que.empty()) {
            auto v = que.top();
            que.pop();
            int value = v.first;
            int x = v.second/n, y = v.second - x*n;
            Max = max(Max, heightMap[x][y]);
            for(auto d:dir) {
                int xx = x + d[0], yy = y + d[1];
                if(xx < 0 || xx >= m || yy < 0 || yy >= n || visited[xx][yy] !=0)   continue;
                visited[xx][yy] = 1;
                if(heightMap[xx][yy] < Max) res += Max - heightMap[xx][yy];
                que.push(pair<int,int>(heightMap[xx][yy], xx*n + yy));
            }
        }
        return res;
    }
};
