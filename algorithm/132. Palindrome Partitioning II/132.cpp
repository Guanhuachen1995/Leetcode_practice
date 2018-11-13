class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n == 0)  return 0;
        
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        vector<vector<bool>> isp = ispal(s, n);
        
        for(int i = 1; i <=n ; i++) {
            
            for(int j = 0; j < i; j++) {
                if(isp[j][i-1] && dp[j] != INT_MAX)
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[n] - 1;
    }
    
    vector<vector<bool>> ispal(string s, int n) {
        vector<vector<bool>>    isp(n, vector<bool>(n, false));
        
        for(int i = 0; i < n; i++) {
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]) {
                isp[l][r] = true;
                l--;
                r++;
            }
        }
        
        for(int i = 0; i < n; i++) {
            int l = i, r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                isp[l][r] = true;
                l--;
                r++;
            }
        }
        return isp;
    }
};
