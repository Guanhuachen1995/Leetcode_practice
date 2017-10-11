class Solution {
    public int[] searchRange(int[] nums, int target) {
        int start = 0, end = nums.length - 1;
        int[] res = {-1,-1};
        if(nums.length == 0)    return res;
        while(start < end)
        {
            int mid = (start + end)/2;
            if(nums[mid] < target)
                start = mid + 1;
            else
                end = mid;
        }
        if(nums[start] != target)   return res;
        res[0] = start;
        
        end = nums.length - 1;
        while(start < end)
        {
            int mid = (start + end)/2 + 1;
            if(nums[mid] > target)
                end = mid - 1;
            else
                start = mid;
        }
        res[1] = end;
        return res;
    }
}
