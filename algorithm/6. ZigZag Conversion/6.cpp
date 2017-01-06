class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string sss[numRows];
        int gap = numRows-2, i = 0; 
        while( i < s.length() )
        {
            for (int j = 0; j < numRows && i < s.size() ; j ++)
                sss[j]+=s[i++];
            for (int j = gap; j > 0 && i < s.size() ; j --)
                sss[j]+=s[i++];
        }
        string result="";
        for (int j =0; j < numRows; j++)
            result+= sss[j];
        return result;
    }
};
