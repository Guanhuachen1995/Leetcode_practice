class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        res.add(new LinkedList<>());
        for(int i = 0; i < nums.length; i++)
        {
            int s = res.size();
            for(int j = 0; j < s; j++)
            {
                List<Integer> tem = new ArrayList<>(res.get(j));
                tem.add(nums[i]);
                res.add(tem);
            }
        }
        return res;
    }
}
