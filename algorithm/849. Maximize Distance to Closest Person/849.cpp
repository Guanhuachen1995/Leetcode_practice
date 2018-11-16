class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> temp(n, 0);
        int cur = -99;
        for(int i = 0; i < n; i++) {
            if(seats[i] == 1)   cur = i;
            temp[i] = i - cur;
        }
        cur = INT_MAX;
        for(int i = n - 1; i >= 0; i--) {
            if(seats[i] == 1)   cur = i;
            temp[i] = min(temp[i], cur - i);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            res = max(res, temp[i]);
        }
        return res;
    }
};
