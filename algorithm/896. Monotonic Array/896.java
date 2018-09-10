class Solution {
    public boolean isMonotonic(int[] A) {
        if(A.length == 1)   return true;
        boolean inc = true, dec = true;
        for(int i = 1; i < A.length; i++) {
            inc &= (A[i] >= A[i-1]);
            dec &= (A[i] <= A[i-1]);
        }
        return inc || dec;
    }
}
