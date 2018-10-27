class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> map;
        unordered_set<string> set;
        return dfs_helper(pattern, str, map, set);
    }
    
     bool dfs_helper(string pattern, string s, 
                    unordered_map<char, string> map,
                    unordered_set<string> set) {
         if(pattern.size() == 0)
             return s.size() == 0;
         
         char c = pattern[0];
         if(map.find(c) != map.end()) {
             if(s.find(map[c]) != 0)    return false;
             return dfs_helper(pattern.substr(1), s.substr(map[c].size()), map, set);
         }
         
         for(int i = 0; i < s.size(); i++) {
             string word = s.substr(0, i + 1);
             if(set.find(word) != set.end())    continue;
             map[c] = word;
             set.insert(word);
             if(dfs_helper(pattern.substr(1), s.substr(word.size()), map, set)) return true;
             set.erase(word);
             map.erase(c);
         }
         return false;
     }
    
};
