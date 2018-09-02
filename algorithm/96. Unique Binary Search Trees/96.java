class Solution {
    public int numTrees(int n) {
        int[] F = new int[n+1];
        F[0] = 1; F[1] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j <= i -1; j++) {
                F[i] += F[j] * F[i - 1 -j];
            }
        }
        return F[n];
    }
}
