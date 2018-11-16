class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int i, j, res =  0, n = seats.size();
        for(i = 0, j = 0; j < n; j++) {
            if(seats[j] == 1) {
                if(i == 0)  res= max(res, j - i);
                else res = max(res, (j - i + 1)/2);
                i = j + 1;
            }
        }
        
        res = max(res, n - i);
        return res;
    }
};
