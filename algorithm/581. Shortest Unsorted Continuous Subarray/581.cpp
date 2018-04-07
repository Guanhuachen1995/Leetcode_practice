class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1,end = -2, min_ = nums[nums.size() - 1], max_ = nums[0];
        for(int i = 0; i <nums.size(); i++)
        {
            min_ = min(min_, nums[nums.size() - 1 -i]);
            max_ = max(max_, nums[i]);
            if(min_ < nums[nums.size() - 1 -i]) start = nums.size() - 1 -i;
            if(max_ > nums[i]) end = i;
        }
        return end - start + 1;
    }
};
