class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> values(n, 0);
        for (int num : nums)
            values[num] += num;
        int skip = 0, take = 0;
        for(int i = 0; i < n; i++) {
            int skipi = max(take, skip);
            int takei = skip + values[i];
            skip = skipi;
            take = takei;
        }
        return max(take, skip);
    }
};
