class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int res = INT_MAX, a = -1, b = -1;
        for(int i = 0; i < words.size(); i++)
        {
            if(words[i] == word1)
            {
                a = i;
                if(b != -1)
                {
                    res = min(res, abs(a - b));
                }
            }
            if(words[i] == word2)
            {
                if(word1 == word2)
                    a = b;
                b = i;
                if(a != -1)
                {
                    res = min(res, abs(a - b));
                }
            }
            
        }
        return res;
    }
};
