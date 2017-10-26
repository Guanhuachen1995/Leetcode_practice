class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> res = new LinkedList<>();
        res.add(0);
        for(int i = 0; i < n; i++)
        {
            int tem = res.size();
            int offset = 1<<i;
            for(int j = tem - 1; j >= 0; j --)
            {
                res.add(res.get(j) + offset);
            }
        }
        return res;
    }
}
