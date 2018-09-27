class Solution {
public:
    /**
     * @param x: a double
     * @return: the square root of x
     */
    double sqrt(double x) {
        // write your code here
        double l = 0.0, r = max(1.0,x), diff = 0.0000000001;
        while(l + diff < r) {
            double mid = l + (r-l)/2;
            if(mid*mid < x)
                l = mid;
            else
                r = mid;
        }
        return r;
    }
};
