class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        sort(nums.begin(), nums.end());
        int res = 1, tem = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i - 1] + 1)
            {
                tem++;
            }
            else if(nums[i] == nums[i - 1] ){
                continue;
            }
            else
            {
                res = max(res, tem);
                tem = 1;
            }
        }
        res = max(res, tem);
        return res;
    }
};
