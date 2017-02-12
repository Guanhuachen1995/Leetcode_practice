class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1.0;
        if(n<0)
        {
            if(n==-2147483648) {  
                return 1.0/ (myPow(x, 2147483647)*x);
            }
            n = -n;
            x=1/x;
        }
        return (n%2 == 0) ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
    }
};
