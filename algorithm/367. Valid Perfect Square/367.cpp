class Solution {
public:
    bool isPerfectSquare(int num) {
        long res=num;
        while(res*res>num)
        {
            res=(res+num/res)/2;
        }
        return res*res==num;
    }
};
