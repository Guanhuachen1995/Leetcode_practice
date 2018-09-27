class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = INT_MIN, sum = 0.0;
        for(int i = 0; i < nums.size(); i++) {
            if(i < k) {
                sum += nums[i];
            } else {
                res = max(res, sum/k);
                sum += nums[i] - nums[i-k];
            }
        }
        res = max(res, sum/k);
        return res;
    }
};
