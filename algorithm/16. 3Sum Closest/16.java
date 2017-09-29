class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int min_diff = Integer.MAX_VALUE, result = 0;
        Arrays.sort(nums);
        for(int i = 0; i < nums.length; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = nums.length - 1;
            while(left < right)
            {
                int diff = nums[i] + nums[left] + nums[right] - target;
                if(Math.abs(diff) < min_diff)
                {
                    min_diff = Math.abs(diff);
                    result = nums[i] + nums[left] + nums[right];
                }
                if(diff < 0)
                    left++;
                else if(diff > 0)
                    right--;
                else
                    return target;
            }
        }
        return result;
    }
}
