class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> memo = vector<vector<bool>>(s.size(), vector<bool>(p.size(), false));
        vector<vector<bool>> visited = vector<vector<bool>>(s.size(), vector<bool>(p.size(), false));
        return helper(s, p, 0,0, memo, visited);
    }
    
    bool helper(string &s, string &p, int sindex, int pindex, vector<vector<bool>> &memo, vector<vector<bool>> &visited) {
        if(pindex == p.size()) {
            return sindex == s.size();
        }
        
        if(sindex == s.size()) {
            return allstar(p,pindex);
        }
        
        
        if(visited[sindex][pindex]) {
            return memo[sindex][pindex];
        }
        
        bool match;
        if(p[pindex] == '*') {
            match = helper(s,p, sindex, pindex + 1, memo, visited) || helper(s, p, sindex + 1, pindex, memo, visited);
        } else {
            match = charmatch(s[sindex], p[pindex]) && helper(s, p, sindex + 1, pindex + 1, memo, visited);
        }
        
        visited[sindex][pindex] = true;
        memo[sindex][pindex] = match;
        
        return match;
    }
    
    bool allstar(string s, int index) {
        while(index < s.size()) {
            if(s[index] != '*')
                return false;
            index++;
        }
        return true;
    }
    
    bool charmatch(char s, char p) {
        return s == p || p == '?';
    }
};
