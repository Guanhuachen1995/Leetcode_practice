class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0,tem=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                if(tem>max)
                    max=tem;
                tem=0;
            }
            else
                tem++;
        }
        if(tem>max)
            max=tem;
        return max;
    }
};
