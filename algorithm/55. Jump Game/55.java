class Solution {
    public boolean canJump(int[] nums) {
        int count = 0;
        for(int i = 0; i <nums.length; i++)
        {
            if(nums[i] >= count)
                count = nums[i];
            else
            {
                count--;
            }
            if(count == 0 && i <nums.length - 1)
                return false;
        }
        return true;
    }
}
