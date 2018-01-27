class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        for(int i = 0; i < (int)rooms.size(); i++)
        {
            for(int j = 0; j < rooms[0].size(); j++)
                if(rooms[i][j] == 0)    helper(rooms, i, j, 0);
        }
    }
    
    
    void helper(vector<vector<int>>& rooms, int i, int j, int d)
    {
        if(i < 0 || i >rooms.size() - 1 || j < 0 || j > rooms[0].size() - 1 || rooms[i][j] < d)
            return;
        rooms[i][j] = d;
        helper(rooms, i + 1, j, d + 1);
        helper(rooms, i - 1, j, d + 1);
        helper(rooms, i, j + 1, d + 1);
        helper(rooms, i, j - 1, d + 1);
    }
};
