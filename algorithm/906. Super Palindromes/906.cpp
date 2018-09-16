class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        int l = sqrt(stol(L)), r = sqrt(stol(R));
        int res = 0;
        vector<int> list;
        helper(list,l,r);
        for(auto n:list) {
            long temp = (long)n*n;
            if(isPalindrome(temp))
                res++;
        }
        return res;
    }
    
    bool isPalindrome(long x) {
        if (x < 0) {
            return false;
        }
        long temp = x;
        long reversed = 0;
        while (temp != 0) {
            reversed = reversed * 10 + temp % 10;
            temp = temp / 10;
        }
        return reversed == x;
    }
    
    int creatPrime(int n, int isodd) {
        int res = n;
        if(isodd == 1)
            res/=10;
        while(n > 0) {
            res = res * 10 + n%10;
            n/=10;
        }
        return res;
    }
    
    void helper(vector<int>& list, int l, int r) {
        int i = 1;
        int num;
        while((num = creatPrime(i, 0)) <= r) {
            if(num >= l)
                list.push_back(num);
            i++;
        }
        i = 1;
        while((num = creatPrime(i, 1)) <= r) {
            if(num >= l)
                list.push_back(num);
            i++;
        }
    }
};
