class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(n, k, cur, 1, res);
        return res;
    }
    
    void helper(int n, int k, vector<int> &cur, int index, vector<vector<int>> &res) {
        if(cur.size() == k) {
            res.push_back(cur);
            return;
        }
        if(index > n) {
            return;
        }
        
        cur.push_back(index);
        helper(n, k, cur, index+1,res);
        cur.pop_back();
        helper(n,k,cur,index+1,res);
        
    }
};
