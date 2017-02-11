class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        for i in range(0,len(matrix[0])/2):
            for j in range(0, len(matrix[0])):
                matrix[i][j], matrix[len(matrix[0])-1-i][j] = matrix[len(matrix[0])-1-i][j], matrix[i][j]
        for i in range(0,len(matrix[0])):
            for j in range(i+1, len(matrix[0])):
                matrix[i][j] , matrix[j][i] =matrix[j][i],matrix[i][j]
