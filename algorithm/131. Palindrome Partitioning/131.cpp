class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        helper(s, 0, cur, res);
        return res;
    }
    
    void helper(string &s, int index, vector<string> &cur, vector<vector<string>> &res) {
        if(index == s.size()) {
            res.push_back(cur);
            return;
        }
        
        for(int i = 1; i <= s.size() - index; i++) {
            string sub = s.substr(index, i);
            if(ispalindrome(sub)) {
                cur.push_back(sub);
                helper(s, index + i, cur, res);
                cur.pop_back();
            }
        }
    }
    
    bool ispalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i] != s[j])    return false;
            i++;
            j--;
        }
        return true;
    }
};
