class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int result=0;
        for (int i=0; i <s.size()&&result<g.size();i++)
        {
            if(g[result]<=s[i]) result++;
        }
        return result;
    }
};
