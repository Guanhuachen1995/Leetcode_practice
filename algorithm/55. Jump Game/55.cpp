class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step=0,max=nums.size();
        for(int i=0; i< nums.size()-1;i++)
        {
            step--;
            if(nums[i]>step)
                step=nums[i];
            if(step==0)
                return false;
        }
        return true;
    }
};
