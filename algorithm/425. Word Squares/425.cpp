class Solution {
public:
    struct TrieNode {
        vector<int> indexs;
        bool isWord = false;
        vector<TrieNode*>   children;
        TrieNode() {
            children = vector<TrieNode*>(26,NULL);
        }
    };
    
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode *root = new TrieNode();
        for(int i = 0; i < words.size(); i++) {
            TrieNode *t = root;
            for(auto c:words[i]) {
                if(t->children[c - 'a'] == NULL)
                    t->children[c - 'a'] = new TrieNode();
                t = t->children[c - 'a'];
                t->indexs.push_back(i);
            }
        }
        return root;
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        TrieNode *root = buildTrie(words);
        vector<vector<string>> res;
        vector<string> out(words[0].size());
        for(int i = 0; i < words.size(); i++) {
            out[0] = words[i];
            helper(words, 1, root, out, res);
        }
        return res;
    }
    
    void helper(vector<string>& words, int level, TrieNode* root, vector<string>& out, vector<vector<string>>& res) {
        if (level >= words[0].size()) {
            res.push_back(out);
            return;
        }
        string str = "";
        for (int i = 0; i < level; ++i) {
            str += out[i][level];
        }
        //剪枝
        TrieNode *t = root;
        for (int i = 0; i < str.size(); ++i) {
            if (!t->children[str[i] - 'a']) return;
            t = t->children[str[i] - 'a'];
        }
        for (int idx : t->indexs) {
            out[level] = words[idx];
            helper(words, level + 1, root, out, res);
        }
    }
};
