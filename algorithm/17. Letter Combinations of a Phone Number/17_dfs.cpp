class Solution {
    const vector<string> keyboard { " ", "", "abc", "def", // '0','1','2',...
            "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0)  return res;
        
        dfs(res, digits, "", 0);
        return res;
    }
    
    void dfs(vector<string> &res, string &digits, string cur, int index) {
        if(index == digits.size()) {
            
            res.push_back(cur);
            return;
        }

        for(auto c:keyboard[digits[index] - '0']) {
            dfs(res, digits, cur+c,index+1);
            
        }
    }
};
