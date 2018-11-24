class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& word1, vector<string>& word2, vector<pair<string, string>> pairs) {
        if(word1.size() != word2.size())    return false;
        unordered_map<string, unordered_set<string>> m;
        
        for(auto p:pairs) {
            m[p.first].insert(p.second);
            m[p.second].insert(p.first);
        }
        
        for(int i = 0; i <word1.size(); i++) {
            if(word1[i] == word2[i]) continue;
            if(m.find(word1[i]) == m.end() || m.find(word2[i]) == m.end())  return false;
            unordered_set<string>   set;
            if(!dfs(m,word1[i], word2[i], set)) return false;
        }
        return true;
    }
    
    bool dfs(unordered_map<string, unordered_set<string>> &m, string word1, string word2, unordered_set<string> &set) {
        if(m[word1].find(word2) != m[word1].end()) return true;
        
        if(set.find(word1) == set.end()) {
            set.insert(word1);
            
            for(auto w:m[word1]) {
                if(set.find(w) == set.end() && dfs(m, w, word2, set))   return true;
            }
        }
        return false;
    }
};
