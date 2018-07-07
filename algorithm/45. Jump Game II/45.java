class Solution {
    public int jump(int[] nums) {
        int res = 0;
        int dis_res = 0;
        int dis_max = 0;
        for(int i = 0; i < nums.length - 1; i++) {
            dis_max = Math.max(dis_max, i + nums[i]);
            if(dis_res == i) {
                res++;
                dis_res = dis_max;
            }
        }
        return res;
    }
}
