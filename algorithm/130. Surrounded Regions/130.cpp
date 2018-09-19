class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0)  return;
        int m = board[0].size();
        if(m == 0)  return;
        for(int i = 0; i < n; i++) {
            checkedge(board, i, 0);
            checkedge(board, i, m - 1);
        }
        
        for(int i = 0; i < m; i++) {
            checkedge(board, 0, i);
            checkedge(board, n - 1, i);
        }
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(board[i][j] == '1')
                    board[i][j] = 'O';
        
    }
    
    
    
    void checkedge(vector<vector<char>> &board, int i, int j) {
        if(board[i][j] == 'O') {
            board[i][j] = '1';
            if(i > 0)
                checkedge(board, i - 1, j);
            if(j > 0)
                checkedge(board, i, j - 1);
            if(i < board.size() - 1)
                checkedge(board, i + 1, j);
            if(i < board[0].size() - 1)
                checkedge(board, i, j + 1);
        }
    }
};
