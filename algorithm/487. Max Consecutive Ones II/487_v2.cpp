class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int zeroLeft = 0, zeroRight = 0, res = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            zeroRight++;
            if(nums[i] == 0) {
                zeroLeft = zeroRight;
                zeroRight = 0;
            }
            res = max(res, zeroRight + zeroLeft);
        }
        return res;
    }
};
