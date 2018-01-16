class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left; i <= right; i++)
        {
            int tem = i;
            while(tem > 0)
            {
                int d = tem%10;
                if(d==0 || i %d != 0)
                {
                    break;
                }
                tem/=10;
            }
            if(tem == 0) res.push_back(i); 
        }
        return res;
    }
};
