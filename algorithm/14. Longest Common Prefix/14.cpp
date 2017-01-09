class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        string result=strs[0];
        for(int i =1; i<strs.size();i++)
        {
            int j;
            for (j = 0; j < result.size() && j < strs[i].size(); ++ j)
            {
                if(result[j]!=strs[i][j])
                    break;
            }
            result = result.substr(0,j);
        }
        return result;
    }
};
