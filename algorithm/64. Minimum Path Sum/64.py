class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m=len(grid)
        n=len(grid[0])
        path = [[grid[0][0] for i in range(n)] for x in range(m)]
        for i in range(1,m):
            path[i][0]= path[i-1][0] + grid[i][0]
        for i in range(1,n):
            path[0][i]= path[0][i-1]+ grid[0][i]
        for i in range(1,m):
            for j in range(1,n):
                path[i][j] = min(path[i-1][j], path[i][j-1])+grid[i][j]
        return path[m-1][n-1]
