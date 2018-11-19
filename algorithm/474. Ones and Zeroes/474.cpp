class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int T = strs.size();
        if(T == 0)  return 0;
        
        vector<int> cnt1(T, 0);
        vector<int> cnt0(T, 0);
        
        for(int i = 0; i < T; i++) {
            for(auto c:strs[i]) {
                if(c == '0')    cnt0[i]++;
                else    cnt1[i]++;
            }
        }
        
        vector<vector<vector<int>>> f(T+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        
        for(int i = 1; i <= T; i++) {
            for(int j = 0; j <= m; j++) {
                for(int k = 0; k <= n; k++) {
                    f[i][j][k] = f[i-1][j][k];
                    if (j >= cnt0[i - 1] && k >= cnt1[i - 1]) {
                        f[i][j][k] = max(f[i][j][k], f[i - 1][j - cnt0[i - 1]][k - cnt1[i - 1]] + 1);
                    }
                }
            }
        }
        return f[T][m][n];
    }
};
