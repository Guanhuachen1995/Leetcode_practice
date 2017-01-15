class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        st=[]
        st.append(-1)
        maxre=0
        for i in xrange(len(s)):
            if s[i]=='(':
                st.append(i)
            else:
                st.pop()
                if len(st)==0:
                    st.append(i)
                else:
                    maxre=max(maxre,i-st[-1])
        return maxre
