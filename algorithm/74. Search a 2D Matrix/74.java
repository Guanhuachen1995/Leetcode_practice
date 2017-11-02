class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length;
        if(n == 0)  return false;
        int m = matrix[0].length;
        if(m == 0)  return false;
        int l = 0; int r = m*n-1;
        while(l < r)
        {
            int mid = (l + r)/2;
            if(matrix[mid/m][mid%m] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return matrix[l/m][l%m] == target;
    }
}
