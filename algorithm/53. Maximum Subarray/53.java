class Solution {
    public int maxSubArray(int[] nums) {
        if( nums.length == 0)   return 0;
        int sum = nums[0];
        int maxsum = sum;
        for(int i = 1; i < nums.length; i++)
        {
            sum = Math.max(nums[i], nums[i] + sum);
            maxsum = Math.max(maxsum, sum);
        }
        return maxsum;
    }
}
