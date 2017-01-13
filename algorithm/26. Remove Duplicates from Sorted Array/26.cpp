class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int result=0;
        for (int i=0;i<nums.size();i++)
        {
            if(nums[result]!=nums[i])
                nums[++result]=nums[i];
        }
        return result+1;
    }
};
