class Solution {
public:
    string reverseWords(string s) {
        string result="", tem;
        istringstream str(s);
        while (str>>tem)
        {
            reverse(tem.begin(),tem.end());
            result+=tem+" ";
        }
        result.pop_back();
        return result;
    }
};
