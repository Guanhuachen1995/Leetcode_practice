class Solution {
    public int primePalindrome(int N) {
        if (N == 1 || N == 2) return 2;
        if (N % 2 == 0) N++;
        while(true) {
            if(isPalindrome(N) == true) {
                if(isPrime(N) == true)
                    return N;
            }
            N += 2;
        }
    }
    
    public boolean isPalindrome(int x) {
        if(x < 0 || (x != 0 && x%10 == 0)) return false;
        int inverse = 0;
        while(x > inverse) {
            inverse = inverse*10 + x%10;
            x /= 10;
        }
        if(x == inverse || x == inverse/10) return true;
        return false;
    }
    
    public boolean isPrime(int x) {
        boolean res = true;
        for(int i = 2; i <= Math.sqrt(x); i++) {
            if(x % i == 0) {
                res = false;
                break;
            }
        }
        return res;
    }
}
