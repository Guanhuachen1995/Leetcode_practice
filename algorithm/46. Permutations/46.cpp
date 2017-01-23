class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()==0)
            return result;
        vector<int> visited;
        DFS(nums, visited, result);
        return result;
    }
    void DFS(vector<int> &num,vector<int> &visited,vector<vector<int> > &result)
    {
        if(num.size() == visited.size()){
            result.push_back(visited);
            return;
        }//if
        vector<int>::iterator isVisited;
        for(int i = 0;i < num.size();i++){
            // 判断num[i]是否已经访问过
           isVisited = find(visited.begin(),visited.end(),num[i]);
           // 如果没有访问过
           if(isVisited == visited.end()){
               visited.push_back(num[i]);
               DFS(num,visited,result);
               visited.pop_back();
           }//if
        }//for
    }
};
