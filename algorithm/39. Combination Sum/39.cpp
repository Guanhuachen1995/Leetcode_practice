class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        helper(candidates,0,target,path,result);
        return result;
    }
    void helper(vector<int> &nums,int index,int target,vector<int>& path,vector<vector<int>> & result)
    {
        if(target==0)
        {
            result.push_back(path);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            if(nums[i]>target)
                break;
            path.push_back(nums[i]);
            helper(nums,i,target-nums[i],path,result);
            path.pop_back();
        }
    }
};
