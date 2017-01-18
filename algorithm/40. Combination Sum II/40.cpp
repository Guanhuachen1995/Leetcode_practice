class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            if(i!=index && nums[i]==nums[i-1])
                continue;
            if(nums[i]>target)
                break;
            path.push_back(nums[i]);
            helper(nums,i+1,target-nums[i],path,result);
            path.pop_back();
        }
    }
    
};
