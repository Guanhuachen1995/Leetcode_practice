class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0)  return 0;
        int k = costs[0].size();
        if(k == 1)  return costs[0][0];
        vector<vector<int>> dp(n+1, vector<int>(k, 0));
        
        for(int i = 1; i <= n; i++) {
            int min1 =INT_MAX, min2 = INT_MAX;
            for(int j = 0; j < k ; j++) {
                if(dp[i-1][j] < min1) {
                    min2 = min1;
                    min1 = dp[i-1][j];
                } else if (dp[i-1][j] < min2)
                    min2 = dp[i-1][j];
            }
            
            for(int j = 0; j < k; j++) {
                dp[i][j] = costs[i-1][j];
                if(dp[i-1][j] != min1)
                    dp[i][j] += min1;
                else
                    dp[i][j] += min2;
            }
        }
        int res = INT_MAX;
        for(int i = 0; i < k; i++) {
            res = min(res, dp[n][i]);
        }
        return res;
    }
};
