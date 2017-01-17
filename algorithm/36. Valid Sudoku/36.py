class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for i in xrange(9):
            m1,m2,m3={},{},{}
            for j in xrange(9):
                if board[i][j]!='.':
                    if m1.has_key(board[i][j])==True:
                        return False
                    else:
                        m1[board[i][j]]=0
                if board[j][i]!='.':
                    if m2.has_key(board[j][i])==True:
                        return False
                    else:
                        m2[board[j][i]]=0
                if board[i/3*3+j/3][i%3*3+j%3]!='.':
                    if m3.has_key(board[i/3*3+j/3][i%3*3+j%3])==True:
                        return False
                    else:
                        m3[board[i/3*3+j/3][i%3*3+j%3]]=0
        return True
