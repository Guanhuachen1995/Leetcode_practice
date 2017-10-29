class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 0;
        int count = 1;
        for(int i = 1; i < chars.size(); i++)
        {
            if(chars[i] == chars[i - 1])
                count++;
            else
            {
                chars[res] = chars[i - 1];
                if(count == 1)
                {
                    res++;
                }
                else
                {
                    res++;
                    int tem = 0, bit = 0;
                    while(count > 0)
                    {
                        tem = tem*10 + count%10;
                        count/=10;
                        bit++;
                    }
                    while(bit-- > 0)    
                    {
                        chars[res] = '0' + tem%10;
                        res++;
                        tem /= 10;
                    }
                }
                count = 1;
            }
        }
        chars[res] = chars[chars.size() - 1];
        if(count == 1)
            res++;
        else
        {
            res++;
            int tem = 0, bit = 0;
            while(count > 0)
            {
                tem = tem*10 + count%10;
                count/=10;
                bit++;
            }
            while(bit-- > 0)    
            {
                chars[res] = '0' + tem%10;
                res++;
                tem /= 10;
            }
        }
        return res;
    }
};
