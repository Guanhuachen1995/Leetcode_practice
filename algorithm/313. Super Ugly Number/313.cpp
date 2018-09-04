class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n);
        vector<int> factor(primes.size());
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            dp[i] = INT_MAX;
            for(int j = 0; j < primes.size(); j++) {
                dp[i] = min(dp[i], dp[factor[j]]*primes[j]);
            }
            
            for(int j = 0; j < primes.size(); j++) {
                while( dp[factor[j]]*primes[j] <= dp[i])    factor[j]++;
            }
        }
        
        return dp[n-1];
    }
};
