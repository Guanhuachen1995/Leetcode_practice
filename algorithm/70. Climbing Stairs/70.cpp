class Solution {
public:
    int climbStairs(int n) {
        if(n<2) return 1;
        vector<int> a(n,1);
        a[1]=2;
        for(int i=2; i<n; i++)
        {
            a[i]=a[i-1]+a[i-2];
        }
        return a[n-1];
    }
};
