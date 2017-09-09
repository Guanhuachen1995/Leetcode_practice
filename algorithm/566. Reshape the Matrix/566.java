class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int a = nums.length, b = nums[0].length;
        if(a*b != r*c)
            return nums;
        int[][] result = new int[r][c];
        for(int i = 0; i < a; i++)
        {
            for(int j = 0; j < b; j++)
                result[(i * b + j)/c][(i * b + j)%c] = nums[i][j];
        }
        return result;
    }
}
