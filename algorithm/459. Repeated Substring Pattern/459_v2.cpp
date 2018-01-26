class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s+s;
        ss = ss.substr(1, ss.size() - 2);
        if(ss.find(s) == -1)    return 0;
        return 1;
    }
};
