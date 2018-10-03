class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame(vector<int> &A) {
        // write your code here
        int n = A.size();
        if(n < 2)   return 0;
        vector<vector<int>> dp(n,vector<int>(n,0));
        vector<vector<int>> sum(n,vector<int>(n,0));
        for(int i = 0; i < n; i++) {
            sum[i][i] = A[i];
            for(int j = i + 1; j < n; j++) {
                sum[i][j] = sum[i][j-1] + A[j];
            }
        }
        
        for(int length = 2; length <= A.size(); length++) {
            for(int i = 0; i < n - length + 1; i++) {
                int temp = INT_MAX;
                int j = i + length - 1;
                for(int mid = i; mid < i + length -1; mid++) {
                    temp = min(temp, dp[i][mid] + dp[mid+1][j] + sum[i][j]);
                }
                dp[i][j] = temp;
            }
        }
        return dp[0][n-1];
    }
};
