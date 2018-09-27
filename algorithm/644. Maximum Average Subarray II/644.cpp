class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double l = INT_MAX, r = INT_MIN, mid;
        for(int n:nums) {
            l = min(l, (double)n);
            r = max(r, (double)n);
        }
        
        while(l + 0.00000001 < r) {
            mid = l + (r - l)/2;
            if(check(nums, mid, k))    l = mid;
            else
                r = mid;
        }
        return l;
    }
    bool check(vector<int>& nums, double mid, int k) {
        double sum = 0, pre_sum = 0, min_sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i] - mid;
            if(i >= k)  {
                pre_sum += nums[i - k] - mid;
                min_sum = min(min_sum, pre_sum);
            }
            if(i >= k-1 && sum - min_sum >= 0 )  return true;
        }
        return false;
    }

};
