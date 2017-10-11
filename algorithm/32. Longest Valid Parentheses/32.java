class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> st = new Stack<Integer>();
        int maxer = 0;
        st.push(-1);
        for(int i = 0; i < s.length(); i++)
        {
            if(s.charAt(i) == '(')
                st.push(i);
            else
            {
                st.pop();
                if(st.isEmpty())
                {
                    st.push(i);
                }
                else
                {
                    maxer = Math.max(maxer, i - st.peek());
                }
            }
        }
        return maxer;
    }
}
