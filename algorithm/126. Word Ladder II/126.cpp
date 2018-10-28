class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, vector<string>& wordList) {
        unordered_map<string, vector<string>> memo;
        unordered_map<string, int> distance;
        vector<vector<string>> result;
        vector<string> path;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        path.push_back(start);
        dict.insert(start);
        //dict.insert(end);
        bfs(start, end, dict, distance, memo);
        dfs(result, path, start, end, distance, memo);
        return result;
    }
    void bfs(string beginWord, string endWord, unordered_set<string>& wordList,
            unordered_map<string, int>& distance, 
            unordered_map<string, vector<string>>& memo) {
        queue<string> q;
        q.push(beginWord);
        distance[beginWord] = 0;
        while(!q.empty()) {
            int num = q.size();
            for(int i = 0; i < num; i++) {
                string temp = q.front();
                q.pop();
                if(temp == endWord) break;
                vector<string> neighbours = findNeighbours(temp, wordList);
                if (memo.find(temp) == memo.end()) memo[temp] = neighbours;
                for (auto& neighbour : neighbours) {
                    if (distance.find(neighbour) != distance.end()) continue;
                    distance[neighbour] = distance[temp] + 1;
                    q.push(neighbour);
                }
            }
        }
    }
    
    vector<string> findNeighbours(string word, unordered_set<string>& wordDict) {
        vector<string> neighbors;
        for(int i = 0; i < word.size(); i++) {
            string temp = word;
            for(int j = 0; j < 26; j++) {
                temp[i] = 'a' + j;
                if(wordDict.find(temp) != wordDict.end() && temp != word) {
                    neighbors.push_back(temp);
                }
            }
        }
        return neighbors;
    }
    
    void dfs (  vector<vector<string>>& result,
                vector<string>& path,
                string& current,
                string& end,
                unordered_map<string, int>& distance,
                unordered_map<string, vector<string>>& memo) {
        if (current == end) {
            result.push_back(path);
            return;
        }
        for (auto neighbour : memo[current]) {
            if ( distance[neighbour] != distance[current] + 1) continue;
            path.push_back(neighbour);
            dfs(result, path, neighbour, end, distance, memo);
            path.pop_back();
        }
    }
};
