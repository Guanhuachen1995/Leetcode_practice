class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        int minus;
        if( x < 0 )
        {
            minus=-1;
            x=-x;
        }
        else
            minus =1;
        while (x>0)
        {
            result = result*10 + x % 10;
            x = x/10;
        }
        result *= minus;
        if (result> INT_MAX || result <INT_MIN)
            return 0;
        else
            return result;
        
    }
};
