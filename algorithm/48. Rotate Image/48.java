class Solution {
    public void rotate(int[][] matrix) {
        for(int i = 0; i < matrix.length/2; i++)
        {
            int[] tem = matrix[i];
            matrix[i] = matrix[matrix.length - 1 - i];
            matrix[matrix.length - 1 - i] = tem;
        }
        for(int i = 0; i < matrix.length; i++)
        {
            for(int j = i + 1; j < matrix.length; j++)
                swap(matrix, i, j);
        }
    }
    
    private void swap(int[][] mat, int a, int b)
    {
        int tem = mat[a][b];
        mat[a][b] = mat[b][a];
        mat[b][a] = tem;
    }
}
