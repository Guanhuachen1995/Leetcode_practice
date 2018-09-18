class Solution {

public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> father(n, -1);
        int count = n;
        for(auto p:edges) {
            int x = find(father, p.first);
            int y = find(father, p.second);
            if(x != y){
                count--;
                father[x] = y;
            } 
            else
                return false;
        }
        if(count!=1)    return false;
        return true;
    }
    
    int find(vector<int>& father, int n) {
        if(father[n] == -1)
            return n;
        father[n] = find(father, father[n]);
        return father[n];
    }
};
