class Solution {
public:
    bool checkRecord(string s) {
        int a=0,l=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='A')
                a++;
            if(s[i]=='L' && i>1 && s[i-1]=='L' &&s[i-2]=='L')
                return 0;
        }
        if(a>1) return false;
        return 1;
    }
};
