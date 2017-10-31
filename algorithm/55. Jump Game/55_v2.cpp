class Solution {
public:
    bool canJump(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i <nums.size(); i++)
        {
            if(nums[i] >= count)
                count = nums[i];
            else
            {
                count--;
            }
            if(count == 0 && i <nums.size() - 1)
                return false;
        }
        return true;
    }
};
