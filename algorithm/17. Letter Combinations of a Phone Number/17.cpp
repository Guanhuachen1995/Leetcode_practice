class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> dict(10); //0~9
        dict[2] = "abc";
        dict[3] = "def";
        dict[4] = "ghi";
        dict[5] = "jkl";
        dict[6] = "mno";
        dict[7] = "pqrs";
        dict[8] = "tuv";
        dict[9] = "wxyz";
        vector<string> ret;
        if(digits == "")
            return ret;
            
        ret.push_back("");
        for (int i=0; i < digits.length();i++)
        {
            int size = ret.size();
            for (int j=0;j< size;j++)
            {
                string tem = ret[0];
                ret.erase(ret.begin());
                for (int k =0; k < dict[digits[i]-'0'].size();k++)
                {
                    ret.push_back(tem+dict[digits[i]-'0'][k]);
                }
                
            }
        }
        return ret;
    }
};
