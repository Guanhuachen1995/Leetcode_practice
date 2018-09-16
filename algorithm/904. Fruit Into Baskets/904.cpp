class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int,int> m;
        int l = 0, res = 0, count = 0;
        for(int r = 0; r < tree.size(); r++) {
            if(m[tree[r]] == 0) {
                count++;
            }
            m[tree[r]]++;
            if(count > 2) {
                while(--m[tree[l++]] > 0);
                count--;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
