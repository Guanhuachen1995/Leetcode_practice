class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        if not(board):
            return 0
        count = 0
        rsize = len(board)
        csize = len(board[0])
        for i in range(0,rsize):
            for j in range (0,csize):
                if board[i][j]=='X' and (i == 0 or board[i-1][j]=='.')and (j == 0 or board[i][j-1]=='.'):
                    count = count + 1
        return count
