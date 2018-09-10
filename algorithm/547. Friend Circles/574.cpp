
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int count = 0;
        vector<int> visited(M.size(),0);
        for(int i = 0; i < M.size(); i++) {
            if(visited[i] == 0) {
                dfs(M, visited, i);
                count++;
            }
        }
        return count;
    }
    
    void dfs(vector<vector<int>>& M, vector<int>& visited, int i) {
        for(int j = 0; j < M.size(); j++) {
            if(M[i][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                dfs(M, visited, j);
            }
        }
    }
};
