class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<int> dp(triangle.back());
        for(int i = row - 2; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};