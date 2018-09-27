class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l + 1 < r) {
            int mid = l + (r - l)/2;
            if(nums[mid] < nums[mid + 1])
                l = mid;
            else if(nums[mid] < nums[mid + 1])
                r = mid;
            else
                r = mid;
        }
        if(nums[l] < nums[r])
            return r;
        else
            return l;
    }
};
