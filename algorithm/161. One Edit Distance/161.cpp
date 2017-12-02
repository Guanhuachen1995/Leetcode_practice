class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.size()<t.size()) return isOneEditDistance(t,s);
        if(s.size() - t.size() > 1)    return false;
        if(s.size() == t.size())
        {
            int diff = 0;
            for(int i = 0; i < s.size(); i++)
            {
                if(s[i] != t[i])
                    diff++;
            }
            if(diff != 1)   return false;
        }
        else
        {
            int i = 0, j = 0;
            while(i < s.size() && j < t.size() && s[i] == t[j])
            {
                i++;
                j++;
            }
            if(s[++i]!=t[j]) return false;
            
            while(i < s.size() && j < t.size())
            {
                if(s[i++]!= t[j++]) return false;
            }
        }
        return true;
    }
};
