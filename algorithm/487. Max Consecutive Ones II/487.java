class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int res = 0, zeroLeft = 0, zeroRight = 0;
        for(int i = 0; i < nums.length; i++) {
            zeroRight++;
            if(nums[i] == 0) {
                zeroLeft = zeroRight;
                zeroRight = 0;
            }
            res = Math.max(res, zeroLeft + zeroRight);
        }
        return res;
    }
}
