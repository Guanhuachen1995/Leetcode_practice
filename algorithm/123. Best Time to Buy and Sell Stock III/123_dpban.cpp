class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0)  return 0;
        vector<vector<int>> f(n+1, vector<int>(5, 0));
        f[0][0] = 0;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 5; j += 2) {
                f[i][j] = f[i-1][j];
                if(i >=2 && j >= 1) f[i][j] = max(f[i-1][j], f[i-1][j-1] + prices[i-1] - prices[i-2]);
            }
            for(int j = 1; j < 5; j += 2) {
                f[i][j] = f[i-1][j-1];
                if(i >= 2) f[i][j] = max(f[i-1][j] + prices[i-1] - prices[i-2], f[i-1][j-1]);
            }
        }
        return max(f[n][0], max(f[n][2], f[n][4]));
    }
};
