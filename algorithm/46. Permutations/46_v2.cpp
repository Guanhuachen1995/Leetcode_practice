class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(0, nums, res);
        return res;
    }
    
    void dfs(int pos, vector<int>& nums, vector<vector<int>> &res)
    {
        if(pos == nums.size())
            res.push_back(nums);
        
        for(int i = pos; i < nums.size(); i++)
        {
            swap(nums[pos], nums[i]);
            dfs(pos + 1, nums, res);
            swap(nums[i], nums[pos]);
        }
    }
};
