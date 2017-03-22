class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0; i<s.size(); i+=2*k)
        {
            for(int j=i,z = min(i + k - 1, (int)s.size() - 1); j < z; j++, z--)
            {
                swap(s[j],s[z]);
            }
        }
        return s;
    }
};
