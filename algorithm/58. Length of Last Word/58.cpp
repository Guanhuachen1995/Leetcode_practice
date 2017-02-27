class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size()-1, result=0;
        while(n>=0 )
        {
            if(s[n--]==' ')
            {
                if(result==0)
                    continue;
                else break;
            }
            else
                result++;
        }
        return result;
    }
};
