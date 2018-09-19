struct TrieNode {
    bool isWord = false;
    vector<TrieNode*> children;
    
    TrieNode() {
        children = vector<TrieNode*>(26, NULL);
    }
};


class Trie {
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        for(char c:word) {
            if(node->children[c-'a'] == NULL){
                node->children[c-'a'] = new TrieNode();
            }
            node = node->children[c-'a'];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = root;
        for(char c:word) {
            //cout<<c-'a'<<endl;
            if(node->children[c-'a'] == NULL) {
                return false;
            }
            node = node->children[c-'a'];
        }
        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(char c:prefix) {
            if(node->children[c-'a'] == NULL)
                return false;
            node = node->children[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
