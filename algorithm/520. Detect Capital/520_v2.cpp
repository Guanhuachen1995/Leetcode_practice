class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() <= 1)    return 1;
        if(!isupper(word[0]))
        {
            for(int i = 1; i < word.size(); i++)
            {
                if(isupper(word[i]))
                    return 0;
            }
        }
        else
        {
            if(isupper(word[1]))
            {
                
                for(int i = 2; i < word.size(); i++)
                {
                    if(!isupper(word[i]))
                        return 0;
                }
            }
            else
            {
                for(int i = 2; i < word.size(); i++)
                {
                    if(isupper(word[i]))
                        return 0;
                }
            }
        }
        return 1;
    }
};
