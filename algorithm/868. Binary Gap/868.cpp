class Solution {
public:
    int binaryGap(int N) {
        int res = 0, zeros = -10000;
        for(; N >  0; zeros++, N /= 2)
        {
            if(N % 2 == 1)
            {
                res = max(res, zeros);
                zeros = 0;
            }
        }
        return res;
    }
};
