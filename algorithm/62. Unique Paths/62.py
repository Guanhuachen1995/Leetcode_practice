class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        mylist = [[1] * n] * m
        for i in range(1,m):
            for j in range(1,n):
                mylist[i][j]=mylist[i-1][j] + mylist[i][j-1]
        return mylist[m-1][n-1]
