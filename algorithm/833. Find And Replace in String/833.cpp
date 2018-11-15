class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>> sorted;
        for (int i = 0 ; i < indexes.size(); i++) sorted.push_back(make_pair(indexes[i], i));
        sort(sorted.rbegin(), sorted.rend());
        for(auto p:sorted) {
            int index = p.first;
            string s = sources[p.second], t = targets[p.second];
            if(S.substr(index, s.size()) == s) S = S.substr(0, index) + t + S.substr(index + s.size());
        }
        return S;
        
    }
};
