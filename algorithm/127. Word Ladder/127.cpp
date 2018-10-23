class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        //s.insert(endWord);
        queue<string> q;
        q.push(beginWord);
        int res = 1;
        while(!q.empty()) {
            int num = q.size();
            for(int i = 0; i < num; i++) {
                string temp = q.front();
                q.pop();
                if(temp == endWord) return res;
                addNextWords(temp, s, q);
            }
            res++;
        }
        return 0;
    }
    
    void addNextWords(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
        wordDict.erase(word);
        for(int i = 0; i < word.size(); i++) {
            string temp = word;
            for(int j = 0; j < 26; j++) {
                temp[i] = 'a' + j;
                if(wordDict.find(temp) != wordDict.end()) {
                    toVisit.push(temp);
                    wordDict.erase(temp);
                }
            }
        }
    }
};
