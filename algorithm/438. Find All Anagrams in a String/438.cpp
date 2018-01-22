class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        unordered_map<char, int> mp;
        for (char c : p) mp[c]++;
        int remaining = p.size(), i = 0, j = 0;
        
        while (j < s.size()) {
            if (mp[s[j]] > 0) remaining--;
            mp[s[j]]--;
            while (mp[s[j]] < 0) { // this covers both duplicates and invalid char cases
                mp[s[i]]++;
                if (mp[s[i]] > 0) remaining++;
                i++;
            } 
            if (remaining == 0) result.push_back(i);
            j++;
        }
        return result;
    }
};
