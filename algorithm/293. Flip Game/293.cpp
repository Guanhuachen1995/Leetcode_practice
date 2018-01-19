class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        int size = s.size();
        for(int i = 0; i < size- 1; i++)
        {
            if(s[i] == '+' && s[i+1] == '+')
            {
                string str = s;
                str.replace(i,2,"--");
                res.push_back(str);
            }
        }
        return res;
    }
};
