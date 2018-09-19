struct trieNode {
    bool isWord = false;
    vector<trieNode*>   children;
    trieNode() {
        children = vector<trieNode*>(26,NULL);
    }
};

class WordDictionary {
private:
    trieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new trieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        trieNode* node = root;
        for(auto c:word) {
            if(node->children[c-'a'] == NULL)
                node->children[c-'a'] =new trieNode();
            node = node->children[c-'a'];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, root);
        
    }
    
    bool search(string& word, int index, trieNode *cur) {
        if(!cur)
            return false;
        if(index == word.size())
            return cur->isWord;
        
        if(word[index] == '.') {
            for(trieNode* child:cur->children) {
                if(search(word, index+1, child))
                    return true;
            }
        } else {
            return search(word, index + 1, cur->children[word[index] - 'a']);
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
