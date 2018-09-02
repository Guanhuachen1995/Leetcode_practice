class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> m;
        int num = 0, i = 0, res = 0;
        for(int j = 0; j < s.size(); j++) {
            if(m[s[j]]++ == 0)  num++;
            if(num > k) {
                while(--m[s[i++]] > 0);
                num--;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};
