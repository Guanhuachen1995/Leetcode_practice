class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> m;
        
        for(int i = 0; i < equations.size(); i++) {
            m[equations[i].first][equations[i].second] = values[i];
            if(values[i] != 0)
                m[equations[i].second][equations[i].first] = 1/values[i];
        }
        vector<double>  res;
        for(auto p:queries) {
            unordered_set<string> set;
            double temp =check(p.first, p.second, m, set);
            if(temp)    res.push_back(temp);
            else 
                res.push_back(-1);
        }
        return res;
        
    }
    
    double check(string up, string down, unordered_map<string, unordered_map<string, double>> &m, unordered_set<string>   &set) {
        if(m[up].find(down) != m[up].end()) return m[up][down];
        
        for(auto p:m[up]) {
            if(set.find(p.first) == set.end()) {
                set.insert(p.first);
                double temp = check(p.first, down, m, set);
                if(temp != 0)   return p.second * temp;
            }
        }
        return 0;
    }
};
