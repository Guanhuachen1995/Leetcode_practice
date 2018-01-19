class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if(heaters.size() == 0)  return 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int res = 0;
        int heaterind = 0;
        for(int i = 0; i < houses.size();i++)
        {
            while(heaterind+1<heaters.size() &&(abs(heaters[heaterind+1] - houses[i]) <= abs(heaters[heaterind] - houses[i])))     heaterind++;
            res = max(res,abs(heaters[heaterind] - houses[i]));
        }
        return res;
    }
};
