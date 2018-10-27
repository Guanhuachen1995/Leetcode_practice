class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> cur;
        DFS(n, res, cur);
        return res;
    }
    
    void DFS(int n,  vector<vector<string>> &res, vector<int> &cur) {
        if(cur.size() == n) {
            res.push_back(drawboard(cur, n));
            return;
        }
        for(int i = 0; i < n; i++) {
            if(!isvaild(cur, i))  continue;
            cur.push_back(i);
            DFS(n, res, cur);
            cur.pop_back();
        }
    }
    
    vector<string>  drawboard(vector<int> &cur, int n) {
        vector<string> res(n, "");
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                res[i] += cur[i] == j?'Q':'.';
            }
        }
        return res;
    }
    
    bool isvaild(vector<int> &cur, int i) {
        int row = cur.size();
        for(int k = 0; k < row; k++) {
            if(cur[k] == i) return false;
            if((k+cur[k]) == (row + i)) return false;
            if((k-cur[k]) == (row - i)) return false;
        }
        return true;
    }
};
