class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < ppid.size(); i++)
        {
            m[ppid[i]].push_back(pid[i]);
        }
        
        vector<int> res;
        queue<int> q;
        q.push(kill);
        while(!q.empty())
        {
            int tem = q.front();
            q.pop();
            res.push_back(tem);
            for(int k:m[tem])
                q.push(k);
        }
        return res;
    }
};
