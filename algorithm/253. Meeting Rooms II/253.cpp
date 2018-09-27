/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int,int>> sweepline;
        for(auto i:intervals) {
            sweepline.push_back(pair<int,int>(i.start, 0));
            sweepline.push_back(pair<int,int>(i.end, 1));
        }
        sort(sweepline.begin(), sweepline.end(), [](pair<int,int>   A, pair<int,int>    B){if(A.first != B.first )
            return A.first < B.first;   else    return A.second > B.second;});
        int res = 0, count = 0;
        for(auto p:sweepline) {
            if(p.second == 0)   count++;
            else count--;
            if(count > res) res = count;
        }
        return res;
    }
};
