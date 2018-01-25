class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gassum = 0, start = 0, tank = 0, costsum = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            if((tank=tank+gas[i]-cost[i])<0)
            {
                start = i+1;
                tank = 0;
            }
            costsum += cost[i];
            gassum += gas[i];
        }
        if( gassum < costsum ) return -1;
        else
            return start;
    }
};
