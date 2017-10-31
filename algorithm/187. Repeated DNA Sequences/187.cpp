class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> map;
        vector<string> res;
        int a = s.size()-9;
        for(int i = 0; i < a; i++)
        {
            if(map.find(s.substr(i,10)) !=map.end())
            {   
                if(map[s.substr(i,10)] == 1)
                {
                    res.push_back(s.substr(i,10));
                    map[s.substr(i,10)]++;
                }
            }
            else
                map[s.substr(i, 10)] = 1;
        }
        return res;
    }
};
