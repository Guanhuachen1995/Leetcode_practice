class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<int> indeg(numCourses,0);
        for(auto pre:prerequisites)
        {
            indeg[pre.first]++;
        }
        queue<int> q;
        for(int i = 0; i < indeg.size(); i++)
        {
            if(indeg[i] == 0)   
            {
                q.push(i);
                indeg[i]--;
            }
        }
        
        
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            res.push_back(v);
            for(auto pre:prerequisites)
            {
                if(pre.second == v)
                    indeg[pre.first]--;
            }
            
            for(int i = 0; i < indeg.size(); i++)
            {
                if(indeg[i] == 0)
                {
                q.push(i);
                indeg[i]--;
                }
            }
        }
        if(res.size()<numCourses) return vector<int>{};
        return res;
    }
};
