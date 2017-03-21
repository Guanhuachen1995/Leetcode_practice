class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()<2)   return 1;
        bool t=0;
        if(word[0]<91)
        {
            if(word[1]<91)
                t=1;
            else
                t=0;
        }
        for(int i=1;i<word.size();i++)
        {
            if(t)
            {
                if(word[i] > 91)
                    return 0;
            }
            else
            {
                if(word[i]<91)
                    return 0;
            }
        }
        return 1;
    }
};
