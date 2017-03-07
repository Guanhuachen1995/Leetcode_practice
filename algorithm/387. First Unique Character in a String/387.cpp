class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> map1;
        for(auto &c:s)
            map1[c]++;
        for(int i=0; i<s.size(); i++)
        {
            if(map1[s[i]]==1) return i;
        }
        return -1;
    }
};
