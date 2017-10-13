class Solution {
    public int firstMissingPositive(int[] nums) {
        if(nums.length == 0)    return 1;
        int l1 = 0;
        Arrays.sort(nums);
        for(int i = 0; i < nums.length; i++)
        {
            if(nums[i] == 1)
                l1 = 1;
            if(nums[i] > 1)
            {
                if(l1 == 0)
                    return 1;
                if(nums[i] - nums[i -1] > 1)
                    return nums[i - 1] + 1;
            }
        }
        return nums[nums.length - 1] + 1;
    }
}
