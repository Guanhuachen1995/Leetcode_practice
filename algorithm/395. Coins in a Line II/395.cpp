class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int n = values.size();
        vector<int> f(n), sum(n);
        int total = 0;
        if(n < 3)  return true;
        for(int i = 0; i < values.size(); i++) {
            total += values[n - 1 -i];
            sum[i] = total;
        }
        f[0] = sum[0];
        f[1] = sum[1];
        for(int i = 2; i < n; i++) {
            f[i] = max(values[n - 1 - i] + (sum[i-1] - f[i - 1]), values[n - 1 - i]+ values[n-i] + sum[i-2] - f[i-2] );
        }
        if(f[n - 1] < sum[n-1] - f[n-1])    return false;
        return true;
    }
};
