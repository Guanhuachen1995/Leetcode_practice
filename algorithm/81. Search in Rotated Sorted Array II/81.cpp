class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        if(end == -1) return 0;
        while(start < end)
        {
            int mid = (start + end) / 2;
            if(nums[mid] == target)
                return 1;
            if(nums[mid] > nums[end])
            {
                if(nums[mid] > target && nums[start] <= target) end = mid;
                else
                    start = mid + 1;
            }
            else if(nums[mid] < nums[end])
            {
                if(nums[mid] < target && nums[end] >= target) start = mid + 1;
                else
                    end = mid;
            }
            else
                end--;
        }
        return nums[start] == target?1:0;
    }
};