class Solution {
public:
    char findTheDifference(string s, string t) {
        char tem=0;
        for(int i=0; i< s.size(); i++)
        {
            tem ^= s[i];
            tem ^= t[i];
        }
        tem^=t[t.size()-1];
        return tem;
    }
};
