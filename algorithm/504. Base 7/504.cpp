class Solution {
public:
    string convertToBase7(int num) {
        int tem,flag=num;
        num=abs(num);
        string res="";
        while(num>=7)
        {
            tem=num%7;
            res=to_string(tem)+res;
            num/=7;
        }
        tem=num%7;
        res=to_string(tem)+res;
        return flag>=0 ? res:("-"+res);
    }
};
