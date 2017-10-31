class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<String>();
        helper(res, "", n,n);
        return res;
    }
    
    public void helper(List<String> list, String str, int left, int right)
    {
        if(left == 0 && right == 0)
        {
            list.add(str);
            return;
        }
        if(left > 0)
            helper(list, str + "(", left - 1, right);
        if(left < right && right > 0)
            helper(list, str + ")", left, right -1);
    }
    
    
}
