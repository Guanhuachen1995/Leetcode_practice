class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int max=0;
        int start = 0;
        for( int i =0 ; i < len; i++ )
        {
            int j = i - 1;
            int k = i + 1;
            while ( j >=0 && k < len && s[j]==s[k])
            {
                j--;
                k++;
            }
            j++;
            k--;
            if(k-j+1>max)
            {
                max=k-j+1;
                start=j;
            }
        }
        for( int i =0 ; i < len; i++ )
        {
            int j = i;
            int k = i + 1;
            while ( j >=0 && k < len && s[j]==s[k])
            {
                j--;
                k++;
            }
            j++;
            k--;
            if(k-j+1>max)
            {
                max=k-j+1;
                start=j;
            }
        }
        
        if (max>0)
        {
            return s.substr(start,  max);
        }
        else
            return NULL;
        
    }
};
