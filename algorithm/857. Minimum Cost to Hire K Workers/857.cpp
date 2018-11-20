class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        vector<pair<double, int>>   vec;
        for(int i = 0; i < quality.size(); i++) {
            vec.push_back(make_pair(1.0*wage[i]/quality[i], quality[i]));
        }
        
        sort(vec.begin(), vec.end(), [](pair<double, int> a, pair<double, int> b) {return a.first < b.first;});
        
        priority_queue<int> pq;
        int nowqualitysum = 0;
        for(int i = 0; i < K; i++) {
            nowqualitysum += vec[i].second;
            pq.push(vec[i].second);
        }
        double res = nowqualitysum * vec[K-1].first;
        for(int i = K; i < n; i++) {
            nowqualitysum += vec[i].second;
            pq.push(vec[i].second);
            nowqualitysum -= pq.top();
            pq.pop();
            res = min(res, nowqualitysum * vec[i].first);
        }
        return res;
    }
};
