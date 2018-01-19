class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int res = wall.size();
        int s = wall.size();
        unordered_map<int, int> map;
        for(auto row:wall)
        {
            int size = 0;
            for(int i = 0; i < row.size() - 1; i++)
            {
                size += row[i];
                map[size]++;
                res = min(res,s-map[size]);
            }
        }
        return res;
    }
};
