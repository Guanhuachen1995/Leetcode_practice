class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int ming = INT_MAX;
        int tem;
        for(int i = 0; i < ghosts.size(); i++)
        {
            tem = abs(ghosts[i][0] - target[0]) + abs(ghosts[i][1] - target[1]);
            ming = min(ming, tem);
        }
        int t = abs(target[0]) + abs(target[1]);
        if(t < ming)
            return true;
        else
            return false;
    }
};
