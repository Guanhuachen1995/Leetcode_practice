class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesis(result,"",n,n);
        return result;
    }
    void generateParenthesis(vector<string>  &v, string s, int l, int r)
    {
        if(l==0 and r==0)
        {
            v.push_back(s);
        }
        if(l>0)
           generateParenthesis(v,s+'(',l-1,r);
        if(l<r && r>0)
            generateParenthesis(v,s+')',l,r-1);
    }
};
