class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s = "", t = "";
        for(auto c:S) if(c == '#')  {
            if(s.size() > 0)    s.pop_back();
        } else s+=c;
        for(auto c:T) if(c == '#')  {
            if(t.size() > 0)    t.pop_back();
        } else t+=c;
        return s == t;
    }
};
