class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if(needle.size() == 0)  return 0;
        for(int i = 0; i < m -n  + 1; i++)
        {
            int j = 0;
            for (; j < needle.size(); j++)
                if (haystack[i + j] != needle[j])
                    break;
            if (j == needle.size()) return i;
        }
        return -1;
    }
};
