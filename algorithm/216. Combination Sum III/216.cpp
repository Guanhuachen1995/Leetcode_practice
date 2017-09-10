class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> num;
        for(int i = 0; i < 9; i++)
            num.push_back(i+1);
        vector<int> comb;
        helper(num, n, comb, 0, result, k);
        return result;
    }
    void helper(vector<int>& cand, int target, vector<int>& comb, int index, vector<vector<int>>& res, int k)
    {
        if(target == 0 && k == 0)
        {
            res.push_back(comb);
            return;
        }
        
        for(int i = index; i < cand.size() && target >= cand[i] && k > 0; i++)
        {
            comb.push_back(cand[i]);
            helper(cand, target - cand[i], comb, i + 1, res, k - 1);
            comb.pop_back();
        }
        return;
    }
};
