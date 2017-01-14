class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;  
        if(dividend<0) sign = -sign;  
        if(divisor<0) sign = -sign;  
        unsigned long c = 1;  
        unsigned long long tmp = abs((long long)dividend);  
        unsigned long long tmp2 = abs((long long)divisor);  
        while(tmp>tmp2){  
            tmp2 = tmp2<<1;  
            c=c<<1;  
        }  
        long long result =0;  
        while(tmp>=abs((long long) divisor)){  
            while(tmp>=tmp2){  
                tmp = tmp - tmp2;  
                result += c;  
            }  
            tmp2 = tmp2>>1;  
            c=c>>1;  
        }  
        result = result*sign;
        if(result > INT_MAX || result < INT_MIN)
            return INT_MAX;
        else
            return result;
    }
};
