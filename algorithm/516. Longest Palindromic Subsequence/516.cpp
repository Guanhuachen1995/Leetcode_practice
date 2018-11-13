class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n == 0)  return 0;
        if(n == 1)  return 1;
        vector<vector<int>> dp(n, vector<int>(n, 1));
        
        for(int i = 0; i < n-1; i++) {
            if(s[i] == s[i+1])  dp[i][i+1] = 2;
        }
        for(int len = 3; len <= n; len++) {
            for(int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                if(s[i] == s[j])    dp[i][j] = max(dp[i][j], dp[i+1][j-1] + 2);
            }
        }
        
        return dp[0][n-1];
    }
};
