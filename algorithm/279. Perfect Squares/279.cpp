class Solution {
public:
    int numSquares(int n) {
        vector<int> dp;
        dp.push_back(0);
        for(int i = 1; i <= n; i++)
        {
            int min1 = INT_MAX;
            int j = 1;
            while(i - j*j >= 0)
            {
                min1 = min(min1, dp[i - j*j] + 1);
                j++;
            }
            dp.push_back(min1);
        }
        return dp[n];
    }
};
