class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, comb, 0, result);
        return result;
    }
    
    void helper(vector<int>& cand, int target, vector<int>& comb, int index, vector<vector<int>>& res)
    {
        if(target == 0)
        {
            res.push_back(comb);
            return;
        }
        
        for(int i = index; i < cand.size() && target >= cand[i]; i++)
        {
            if(i == index || cand[i] != cand[i - 1])
            {
                comb.push_back(cand[i]);
                helper(cand, target - cand[i], comb, i + 1, res);
                comb.pop_back();
            }
        }
        return;
    }
};
