class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int start=-1,end=-1;
        for (int i = 0; i< nums.size();i++)
        {
            if(nums[i]<target)
                continue;
            if(nums[i]==target)
            {
                if(start==-1)
                    start=i;
                end=i;
            }
            if(nums[i]>target)
                break;
        }
        result.push_back(start);
        result.push_back(end);
        return result;
    }
};
