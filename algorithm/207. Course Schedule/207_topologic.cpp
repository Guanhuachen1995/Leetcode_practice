class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>>  edges(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto p:prerequisites) {
            edges[p.second].insert(p.first);
            indegree[p.first]++;
        }
        
        queue<int>  q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        int nodes = 0;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            nodes++;
            for(auto i:edges[x]) {
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
        return nodes == numCourses;
        
    }
};
