class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //s0 = profit having no stock
        //s1 = profit having 1 stock
        int s0 = 0, s1 = INT_MIN;
        
        for(int p:prices)
        {
            int tem = s0;
            s0 = max(s0, s1 + p);
            s1 = max(s1, s0-fee -p);
        }
        return max(s0,s1);
    }
};
