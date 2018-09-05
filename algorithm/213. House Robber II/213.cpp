class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        return max(robb(nums, 0 , n - 1), robb(nums, 1 , n));
    }
    
    int robb(vector<int>& nums, int s, int e) {
        int pre = 0, cur = 0;
        for(int i = s; i < e; i++) {
            int tem = max(pre + nums[i], cur);
            pre = cur;
            cur = tem;
        }
        return cur;
    }
};
