class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> comb;
        sort(nums.begin(), nums.end());
        helper(nums, res, comb, 0);
        return res;
    }
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& comb, int index)
    {
        res.push_back(comb);
        for(int i = index; i < nums.size(); i++)
        {
            if(i == index || nums[i] != nums[i - 1] )
            {
                comb.push_back(nums[i]);
                helper(nums, res, comb, i + 1);
                comb.pop_back();
            }
        }
    }
};
