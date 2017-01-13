class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.empty() && needle.empty())
            return 0;
        if (needle.size() == 0)
            return 0;
        if (haystack.size() < needle.size())
            return -1;

        return KMP(haystack,needle);
    }
    //求子字符串的k值
    vector<int> getNext(string tmp) {
        int i = tmp.size();
        int j = 0;
        int k = -1;
        vector<int> ans(i);
        ans[0] = -1;
        while (j < i-1) {
            if (k == -1 || tmp[j] == tmp[k]) {
                k++;
                j++;
                ans[j] = k;
            } else {
                k = ans[k];
            }
        }
        return ans;
    }
    int KMP(string s, string sub) {
        int i = 0;
        vector<int> next = getNext(sub);
        int j = 0;
        while (i < s.size()) {
            if (j == -1 || s[i] == sub[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
            if (j == sub.size())
                return i-j;
        }
        return -1;
    }
};
