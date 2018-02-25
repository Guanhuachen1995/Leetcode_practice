class Solution {
public:
    int rotatedDigits(int N) {
        int res = 0;
        for(int i = 0; i<= N; i++)
        {
            if(help(i)) res++;
        }
        return res;
    }
    
    bool help(int n)
    {
        bool change = 0;
        int k;
        while(n>0)
        {
            k = n%10;
            if(k == 3 || k == 4 || k==7)
                return 0;
            else if(k == 2 || k == 5 || k ==6 || k==9)
                change = 1;
            n/=10;
        }
        if(change == 1)
            return 1;
        else
            return 0;
    }
};
