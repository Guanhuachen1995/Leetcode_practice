class Solution {
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        int[] res = new int[nums.length];
        int l = 0, r = nums.length - 1;
        int index = (a >= 0)?nums.length - 1:0;
        while(l <= r) {
            int lnum = getNum(nums[l],a,b,c);
            int rnum = getNum(nums[r],a,b,c);
            if(a >= 0) {
                if(lnum >= rnum) {
                    res[index--] = lnum;
                    l++;
                } else {
                    res[index--] = rnum;
                    r--;
                }
            } else {
                if(lnum <= rnum) {
                    res[index++] = lnum;
                    l++;
                } else {
                    res[index++] = rnum;
                    r--;
                }
            }
        }
        return res;
    }
    
    public int getNum(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
}
