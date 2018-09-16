class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> result;
        int remove_left = 0, remove_right = 0;
        for(auto c:s) {
            if(c == '(')
                remove_left++;
            else if(c == ')') {
                if(remove_left > 0) remove_left--;
                else
                    remove_right++;
            }
        }
        helper(0,0,s,remove_left,remove_right,"",result);
        return vector<string>(result.begin(), result.end());
    }
    
    void helper(int pair, int index,const string &s, int remove_left, int remove_right, string solution, unordered_set<string> &res) {
        if(index == s.size()) {
            if(pair == 0 && remove_left == 0 && remove_right == 0) res.insert(solution);
            return;
        }
        if(s[index]=='(') {
            if(remove_left > 0) helper(pair, index + 1, s, remove_left - 1, remove_right, solution, res);
            helper(pair+1, index + 1, s, remove_left, remove_right, solution + s[index], res);
        } else if(s[index]== ')') {
            if(remove_right > 0) helper(pair, index + 1, s ,remove_left, remove_right - 1, solution, res);
            if(pair>0)  helper(pair - 1, index + 1, s, remove_left, remove_right, solution + ')', res);
        } else {
            helper(pair, index + 1, s, remove_left, remove_right, solution + s[index], res);
        }
    }
};
