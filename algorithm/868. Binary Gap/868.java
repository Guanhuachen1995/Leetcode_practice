class Solution {
    public int binaryGap(int N) {
        int res = 0, zeros = -99;
        for(; N > 0; N /= 2, zeros++) {
            if(N % 2 == 1) {
                res = Math.max(res, zeros);
                zeros = 0;
            }
        }
        return res;
    }
}
