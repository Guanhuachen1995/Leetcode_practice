class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, result, comb, 0);
        return result;
    }
    
    
    void helper(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& combination, int index)
    {
        if(target == 0)
        {
            result.push_back(combination);
            return;
        }
        for(int i =index; i < candidates.size() && target >= candidates[i]; i++)
        {
            combination.push_back(candidates[i]);
            helper(candidates, target - candidates[i], result, combination, i);
            combination.pop_back();            
        }
        return;
    }
};
