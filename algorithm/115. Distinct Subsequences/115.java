class Solution {
    public int numDistinct(String s, String t) {
        int n = t.length(), m = s.length();
        int[][] dp = new int[n+1][m+1];
        for(int i = 0; i <= m; i++)
            dp[0][i] = 1;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(s.charAt(j) == t.charAt(i))
                    dp[i+1][j+1] = dp[i][j] + dp[i+1][j];
                else
                    dp[i+1][j+1] = dp[i+1][j];
            }
        }
        return dp[n][m];
    }
}
