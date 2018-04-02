class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int imax = nums[0], imin = nums[0], res = nums[0];
        
        for(int i = 1; i < len; i++)
        {
            if(nums[i] < 0)
                swap(imin, imax);
            imax = max( nums[i], imax * nums[i]);
            imin = min( nums[i], imin * nums[i]);
            res = max(res,imax);
        }
        return res;
    }
};
