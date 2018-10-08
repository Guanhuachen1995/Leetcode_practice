class TrieNode {
public:
    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = NULL;

        hasWord = false;
    }
    TrieNode* children[26];
    bool hasWord;
    string str;

    // Inserts a word into the trie.
    static void addWord(TrieNode* root, string& word) {
        TrieNode *p = root;
        for(int i = 0; i < word.size(); i++){
            if (p->children[word[i] - 'a'] == NULL) {
                p->children[word[i] - 'a'] = new TrieNode();
            }
            p = p->children[word[i] - 'a'];
        }
        p->hasWord = true;
        p->str = word;
    }
 
};

class Solution {
public:
    /**
     * @param words: a set of stirngs
     * @param target: a target string
     * @param k: An integer
     * @return: output all the strings that meet the requirements
     */
    vector<string> kDistance(vector<string> &words, string &target, int k) {
        // write your code here
        TrieNode* root = new TrieNode();
        for(auto s:words)
            TrieNode::addWord(root, s);
        int n = target.size();
        vector<string>  res;
        vector<int> dp(n+1, 0);
        for(int i = 0; i <= n; i++) {
            dp[i] = i;
        }
        
        find(root, res, k, target, dp);
        return res;
    }
    
    
    void find(TrieNode* node, vector<string>& result, int k, string& target, vector<int>& dp) {
        int n = target.size();

        if(node->hasWord && dp[n] <= k) result.push_back(node->str);
        vector<int> newdp(n+1, 0);
        for(int i = 0; i < 26; i++) {
            if(node->children[i] != NULL) {
                newdp[0] = dp[0] + 1;
                for(int j = 1; j <=n; j++) {
                    if(target[j-1] - 'a' == i) {
                        newdp[j] =  dp[j - 1];//min(dp[j - 1], min(newdp[j - 1] + 1, dp[j] + 1));
                    } else {
                        newdp[j] = min(dp[j-1] + 1, min (dp[j] + 1, newdp[j-1] + 1));
                    }
                }
                find(node->children[i], result, k, target, newdp);
            }
        }
        
        
    }
};
