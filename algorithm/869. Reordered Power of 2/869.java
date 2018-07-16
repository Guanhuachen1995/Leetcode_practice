class Solution {
    public boolean reorderedPowerOf2(int N) {
        int cnt = counter(N);
        for(int i = 0; i < 32; i++) {
            if(counter(1<<i) == cnt)    return true;
        }
        return false;
    }
    
    
    private int  counter(int N) {
        int res = 0;
        while(N > 0) {
            res += Math.pow(10, N%10);
            N /= 10;
        }
        return res;
    }
}
