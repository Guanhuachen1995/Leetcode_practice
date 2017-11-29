class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        helper(word, res, 0 , "", false);
        return res;
    }
    
    void helper(string word, vector<string> &res, int pos, string tem, bool pre)
    {
        if(pos == word.size())
        {
            res.push_back(tem);
            return;
        }
        
        helper(word, res, pos + 1, tem + word[pos], false);
        if(!pre)
        {
            for(int i = 1; i <= word.size() - pos; i++)
                helper(word, res, pos + i, tem + to_string(i), true);
        }
    }
};
