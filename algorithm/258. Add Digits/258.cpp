class Solution {
public:
    int addDigits(int num) {
        while(num >= 10)
        {
            int tem = 0;
            while(num>0)
            {
                tem += num%10;
                num/=10;
            }
            num = tem;
        }
        return num;
    }
};
