class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0)  return 0;
        if(n == 1)  return k;
        int sam = k, diff = k*(k-1);
        for(int i = 2; i < n; i++)
        {
            int tem = sam;
            sam = diff;
            diff = (tem+diff)*(k-1);
        }
        return sam + diff;
    }
};
