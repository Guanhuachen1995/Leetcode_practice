class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num==1) return 0;
        int result=1,tem=2;
        while(tem*tem<=num)
        {
            if(num%tem==0)
            {
                result+=tem;
                if(num/tem!=tem)
                    result+=num/tem;
            }
            tem++;
        }
        return result==num;
    }
};
