class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
            return;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int lives = neighbor(board, m, n, i, j);
                if(board[i][j] == 1 && lives>=2 && lives <= 3)
                    board[i][j] = 3;
                if(board[i][j] == 0 && lives ==3)
                    board[i][j] = 2;
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                board[i][j] = board[i][j]>>1; 
        }
    }
    
    int neighbor(vector<vector<int>>& board, int m, int n, int i, int j)
    {
        int res = 0;
        for(int a = max(0, i -1); a <= min(m - 1, i + 1); a++)
        {
            for(int b = max(0, j - 1); b <= min(n - 1, j + 1); b++)
                res += board[a][b] & 1;
        }
        res -= board[i][j] & 1;
        return res;
    }
};
