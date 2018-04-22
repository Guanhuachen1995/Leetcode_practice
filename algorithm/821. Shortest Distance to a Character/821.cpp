class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size(), pos = -n;
        vector<int> res(n,n);
        for(int i = 0; i <S.size(); i++)
        {
            if(S[i] == C)   pos = i;
            res[i] = min(res[i], abs(i - pos));
        }
        for(int i = n - 1; i >= 0; i--)
        {
            if(S[i] == C)   pos = i;
            res[i] = min(res[i], abs(i - pos));
        }
        return res;
    }
};
