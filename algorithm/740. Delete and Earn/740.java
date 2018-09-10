class Solution {
    public int deleteAndEarn(int[] nums) {
        int n = 10001;
        int[] values = new int[n];
        for(int i = 0; i < nums.length; i++) {
            values[nums[i]] += nums[i];
        }
        
        int take =0, skip = 0;
        for(int i = 0; i < n; i++) {
            int takei = skip + values[i];
            int skipi = Math.max(skip, take);
            skip = skipi;
            take = takei;
        }
        return Math.max(skip, take);
    }
}
