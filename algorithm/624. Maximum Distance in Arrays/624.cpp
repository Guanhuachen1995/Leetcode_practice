class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0;
        int minnum = arrays[0][0], maxnum = arrays[0][arrays[0].size() - 1];
        for(int i = 1; i < arrays.size(); i++)
        {
            res = max(res, abs(minnum - arrays[i][arrays[i].size() - 1]));
            res = max(res, abs(maxnum - arrays[i][0]));
            minnum = min(minnum, arrays[i][0]);
            maxnum = max(maxnum, arrays[i][arrays[i].size() - 1]);
        }
        return res;
    }
};
