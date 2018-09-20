class Solution {
private:
    int find(int x, vector<int> &father) {
        if(father[x] == x)
            return x;
        father[x] = find(father[x],father);
        return father[x];
    }
    

public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if(n <= 0 || m <= 0)    return res;
        int count = 0;
        vector<int> father(n*m, -1);
        vector<pair<int, int>> dirs = {{0,1},{0, -1}, {-1, 0}, {1, 0}};
        for(auto p:positions) {
            int index = p.first * n + p.second;
            father[index] = index;
            count++;
            for(auto d:dirs) {
                int x = p.first + d.first;
                int y = p.second + d.second;
                int ind = x * n + y;
                if(x < 0 || x >= m || y < 0 || y >= n || father[ind] == -1) continue;
                
                int rootnb = find(ind,father);
                int root = find(index,father);
                if(root != rootnb) {
                    father[root] = rootnb;
                    count--;
                }
                
            }
            res.push_back(count);
        }
        return res;
    }
};
