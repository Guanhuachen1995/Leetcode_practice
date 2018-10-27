class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> cur;
        DFS(n, res, cur);
        return res;
    }
    
    void DFS(int n,  int &res, vector<int> &cur) {
        if(cur.size() == n) {
            res++;
            return;
        }
        for(int i = 0; i < n; i++) {
            if(!isvaild(cur, i))  continue;
            cur.push_back(i);
            DFS(n, res, cur);
            cur.pop_back();
        }
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
