class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string>  result;
        for(int i = 0; i < 12; i++)
        {
            for(int j = 0; j < 60; j++)
            {
                int tem = 0;
                int k = i*64+j;
                while(k > 0)
                {
                    if(k%2 == 1)    tem++;
                    k/=2;
                }
                if(tem == num)
                {
                    result.push_back(to_string(i)+(j<10?":0":":")+to_string(j));
                }
            }
        }
        return result;
    }
};
