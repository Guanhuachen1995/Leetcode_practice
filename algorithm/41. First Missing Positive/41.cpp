class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0)
            return 1;
        sort(nums.begin(),nums.end());
        int i1=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                i1=1;
            if(nums[i]>1)
            {
                if(i1==0)
                    return 1;
                if(nums[i]-nums[i-1]>1)
                {
                    return nums[i-1]+1;
                }
            }
        }
        return nums[nums.size()-1]+1;
    }
};
