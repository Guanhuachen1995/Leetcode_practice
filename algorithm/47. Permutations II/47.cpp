class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()==0)
            return result;
        sort(nums.begin(),nums.end());
        vector<int> visited;
        vector<bool> used(nums.size(),false);
        DFS(nums,used, visited, result);
        return result;
    }
    
    void DFS(vector<int> &num,vector<bool> &used ,vector<int> &visited,vector<vector<int> > &result)
    {
        if(num.size() == visited.size()){
            result.push_back(visited);
            return;
        }//if
        
        for(int i = 0;i < num.size();i++){
            // 判断num[i]是否已经访问过
            if(used[i] ||(i>0 && num[i]==num[i-1] && !used[i-1]))
                continue;
            used[i]=true;
               visited.push_back(num[i]);
               DFS(num,used,visited,result);
               visited.pop_back();
               used[i]=false;
        }//for
    }
};
