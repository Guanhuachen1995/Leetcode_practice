class Solution {
    unordered_map<string, bool> m;
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size())  return false;
        
        if(m.find(s1+'_'+s2) != m.end())    return m[s1+"_"+s2];
        int n = s1.size();
        if(n == 1)  return s1 == s2;
        for(int i = 1; i < n; i++) {
            //cout<<s1.substr(0, i)<<"   "<<s2.substr(n-i,i)<<"   "<<s1.substr(i,n-i)<<"   "<<s2.substr(0,n-i)<<endl;
            if((isScramble(s1.substr(0, i), s2.substr(0,i)) && (isScramble(s1.substr(i, n-i), s2.substr(i,n-i)))) ||
               (isScramble(s1.substr(0, i), s2.substr(n-i,i)) && (isScramble(s1.substr(i,n-i), s2.substr(0,n-i))))) {
                cout<<s1.substr(0, i)<<endl;
                m[s1 + '_' + s2] = true;
                return true;
            }
        }
        m[s1 + '_' + s2] = false;
        return false;
    }
};
