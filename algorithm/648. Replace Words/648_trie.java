class Solution {
    public String replaceWords(List<String> dict, String sentence) {
        TrieNode trie = new TrieNode();
        
        for(String root: dict) {
            TrieNode cur = trie;
            for(char letter:root.toCharArray()) {
                if(cur.children[letter - 'a'] == null)
                    cur.children[letter - 'a'] = new TrieNode();
                cur = cur.children[letter - 'a'];
            }
            cur.word = root;
        }
        
        StringBuilder res = new StringBuilder();
        for(String word: sentence.split("\\s+")) {
            TrieNode cur = trie;
            for(char letter:word.toCharArray()) {
                if(cur.children[letter - 'a'] == null || cur.word != null)
                    break;
                cur = cur.children[letter - 'a'];
            }
            if(res.length()!=0)   res.append(" ");
            res.append(cur.word != null ? cur.word : word);
        }
        return res.toString();
    }
    
    class TrieNode {
        TrieNode[] children;
        String word;
        TrieNode() {
            children = new TrieNode[26];
        }
    }
}
