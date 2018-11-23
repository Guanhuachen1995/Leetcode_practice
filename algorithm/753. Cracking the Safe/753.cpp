class Solution {
public:
    string crackSafe(int n, int k) {
        string res ="";
        for(int i = 0; i < n; i++)  res += "0";
        int goal = pow(k, n);
        unordered_set<string>   visited;
        visited.insert(res);
        
        dfs(res, goal, visited, n, k);
        
        return res;
    }
    
    bool dfs(string &sb, int goal, unordered_set<string> &visited, int n, int k) {
        if(visited.size() == goal)  return true;
        string prev = sb.substr(sb.size() - n + 1);
        for(int i = 0; i < k; i++) {
            string next = prev + to_string(i);
            if(visited.find(next) == visited.end()) {
                visited.insert(next);
                sb += to_string(i);
                if(dfs(sb, goal, visited, n, k))    return true;
                else {
                    sb.pop_back();
                    visited.erase(next);
                }
            }
        }
        return false;
    }
};
