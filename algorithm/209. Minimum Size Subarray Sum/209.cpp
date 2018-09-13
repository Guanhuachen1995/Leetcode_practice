class Solution {
public:
    /**
     * @param nums: an array of integers
     * @param s: An integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        int res = INT_MAX;
        int l = 0, r = 0, sum = 0;
        
        while(r < nums.size()) {
            while(sum < s && r < nums.size()) {
                sum += nums[r++];
            }
            if (sum < s) break;
            while(sum >= s && l < r) {
                sum -= nums[l++];
            }
            res = min(res, r - l + 1);
        }
        return res == INT_MAX?-1:res;
    }
};
