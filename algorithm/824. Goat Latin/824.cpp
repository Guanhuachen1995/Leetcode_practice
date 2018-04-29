class Solution {
public:
    string toGoatLatin(string S) {
        string res = "";
        int start = 0, count = 0;
        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] == ' ')
            {
                
                if(start < i)
                {
                    string tem = S.substr(start, i - start);
                    if(tolower(tem[0])== 'a' || tolower(tem[0])== 'e' || tolower(tem[0]) == 'i' || tolower(tem[0]) == 'o' || tolower(tem[0]) == 'u')
                    {
                        tem += "ma";
                    }
                    else
                    {
                        char tem2 = tem[0];
                        tem = tem.substr(1,tem.size()-1) + tem2;
                        tem += "ma";
                        
                    }
                    count++;
                    for(int j = 0; j < count; j++)
                        tem += "a";
                    
                    res += tem + " ";
                }
                start = i + 1;
            }
            
        }
        if(start < S.size())
        {
            string tem = S.substr(start, S.size() - start);
            if(tolower(tem[0])== 'a' || tolower(tem[0])== 'e' || tolower(tem[0]) == 'i' || tolower(tem[0]) == 'o' || tolower(tem[0]) == 'u')
                {
                    tem += "ma";
                }
                else
                {
                    char tem2 = tem[0];
                    tem = tem.substr(1,tem.size()-1) + tem2;
                    tem += "ma";
                }
                count++;
                for(int j = 0; j < count; j++)
                    tem += "a";
                
                res += tem ;
        }
        return res;
    }
};
