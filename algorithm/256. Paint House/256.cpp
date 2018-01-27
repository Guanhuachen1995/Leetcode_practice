class Solution {
public:
    int minCost(vector<vector<int>>& cost) {
        if(cost.size() == 0)
            return 0;
        for(int i = 1; i < cost.size(); i++)
        {
            cost[i][0] = min(cost[i-1][1], cost[i-1][2]) + cost[i][0];
            cost[i][1] = min(cost[i-1][0], cost[i-1][2]) + cost[i][1];
            cost[i][2] = min(cost[i-1][0], cost[i-1][1]) + cost[i][2];
        }
        int n = cost.size() - 1;
        return min(cost[n][0],min(cost[n][1], cost[n][2]));
    }
};
