class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool result=1;
        for(int i=0; i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else
            {
                if(!st.empty()&&((s[i]==')' && st.top()=='(')||(s[i]=='}' && st.top()=='{')||(s[i]==']' && st.top()=='[')))
                    st.pop();
                else
                {
                    result=0;
                    break;
                }
            }
        }
        if(!st.empty())
            result=0;
        return result;
    }
};
