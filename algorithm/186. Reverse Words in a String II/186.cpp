class Solution {
public:
    void reverseWords(vector<char>& str) {
        reverseString(str, 0, str.size() - 1);
        
        int start = 0;
        for(int i = 0; i< str.size(); i++)
        {
            if(str[i] == ' ')
            {
                reverseString(str, start, i - 1);
                start = i + 1;
            }
        }
        reverseString(str, start, str.size() - 1);
    }
    
    void reverseString(vector<char> &s, int i, int j) {
        while(i < j)
        {
            char tem= s[i];
            s[i] = s[j];
            s[j] = tem;
            i++;
            j--;
        }
    }
};
