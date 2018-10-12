class Solution {
public:
    string frequencySort(string s) {
        vector<string>  bucket(s.size(), "");
        unordered_map<char, int> m;
        string res;
        
        for(auto c:s) {
            m[c]++;
        }
        
        for(auto it:m) {
            int c = it.first;
            int num = it.second;
            bucket[num-1].append(num,c);
        }
        
        for(int i = s.size() - 1; i >= 0; i--) {
            res += bucket[i];
        }
        return res;
    }
};
