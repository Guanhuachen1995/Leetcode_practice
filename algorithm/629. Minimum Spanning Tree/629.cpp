/**
 * Definition for a Connection.
 * class Connection {
 * public:
 *   string city1, city2;
 *   int cost;
 *   Connection(string& city1, string& city2, int cost) {
 *       this->city1 = city1;
 *       this->city2 = city2;
 *       this->cost = cost;
 * }
 */
 
bool com(Connection &c1, Connection &c2) {
    if(c1.cost != c2.cost)
        return c1.cost < c2.cost;
    if(c1.city1 != c2.city1)
        return c1.city1 < c2.city1;
    return c1.city2 < c2.city2;
    
}
 
class Solution {
public:
    /**
     * @param connections given a list of connections include two cities and cost
     * @return a list of connections from results
     */
    vector<Connection> lowestCost(vector<Connection>& connections) {
        // Write your code here
        sort(connections.begin(), connections.end(), com);
        int n=0;
        unordered_map<string, int> m;
        for(Connection con:connections) {
            if(m.count(con.city1) == 0)
                m[con.city1] = ++n;
            if(m.count(con.city2) == 0)
                m[con.city2] = ++n;
        }
        vector<Connection> res;
        vector<int> father(n+1, 0);
        
        for(Connection con:connections) {
            int mnum1 = m[con.city1];
            int mnum2 = m[con.city2];
            
            int x = find(mnum1, father);
            int y = find(mnum2, father);
            
            if(x != y) {
                res.push_back(con);
                father[x] = y;
            }
        }
        if(res.size() != n-1)
            return vector<Connection>();
        return res;
    }
    
    
    int find(int x, vector<int> &father) {
        if(father[x] == 0)
            return x;
        father[x] = find(father[x], father);
        return father[x];
    }
};
