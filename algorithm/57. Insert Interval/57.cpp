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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res1,res2;
        int s = newInterval.start, e = newInterval.end;
        for(int i = 0; i < intervals.size(); i++)
        {
            if(intervals[i].end< s)
                res1.push_back(intervals[i]);
            else if (intervals[i].start > e)
                res2.push_back(intervals[i]);
            else
            {
                s = min(s, intervals[i].start);
                e = max(e, intervals[i].end);
            }
        }
        res1.push_back(Interval(s,e));
        res1.insert(res1.end(),res2.begin(),res2.end());
        return res1;
        
    }
};
