class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string result="";
        int count=0;
        while(num && count<8)
        {
            int tem=num & 15;
            char a;
            if(tem<10)
            {
                a=('0'+tem);
                result=a+result;
            }
            else
            {
                a=('a'+tem-10);
                result= a+result;
            }
            num = num>>4;
            count++;
        }
        return result;
    }
};
