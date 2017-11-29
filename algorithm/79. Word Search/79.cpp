class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int x = 0; x < board.size(); x++)
        {
            for(int y = 0; y < board[0].size(); y++)
                if(helper(board, word, 0, x, y)) return true;
        }
        return false;
    }
    
    bool helper(vector<vector<char>>& board, string word, int i, int x, int y)
    {
        if(i == word.size())    return true;
        if(x < 0 || y < 0 || x >= board.size()|| y >= board[0].size())  return false;
        if(board[x][y] != word[i])  return false;
        board[x][y] = '!';
        bool tem = helper(board, word, i+1, x+1,y) || 
            helper(board, word, i+1, x-1,y) || 
            helper(board, word, i+1, x,y+1) || 
            helper(board, word, i+1, x,y-1);
        board[x][y] = word[i];
        return tem;
    }
};
