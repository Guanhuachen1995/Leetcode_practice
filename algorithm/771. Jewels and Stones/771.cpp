class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        unordered_map<char, int> m;
        for(int i = 0; i <S.size(); i++)
            m[S[i]]++;
        for(int  i = 0; i < J.size(); i++)
        {
            if(m.count(J[i]) > 0)
                res+= m[J[i]];
        }
        return res;
    }
};
