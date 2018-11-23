class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones.size() == 0)  return true;
        
        unordered_map<int, unordered_set<int>>  m; // stone to step set;
        
        for(auto s:stones)  m[s] = {};
        m[0].insert(1);
        for(int i = 0; i < stones.size() - 1; i++) {
            int stone = stones[i];
            for(int step:m[stone]) {
                int reach = step +stone;
                if(reach == stones[stones.size() - 1])  return true;
                
                if(m.find(reach) != m.end()) {
                    if(step > 1)    m[reach].insert(step - 1);
                    m[reach].insert(step);
                    m[reach].insert(step + 1);
                }
            }
        }
        
        return false;
    }
};
