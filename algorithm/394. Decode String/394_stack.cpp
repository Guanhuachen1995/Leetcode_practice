class Solution {
public:
    /**
     * @param s: an expression includes numbers, letters and brackets
     * @return: a string
     */
    string expressionExpand(string &s) {
        // write your code here
        stack<string>   st;
        for(char  c:s) {
            if (c !=']') {
                st.push(string(1, c));
            } else {
                string tem = "";
                while(!st.empty() && st.top() != "[") {
                    tem = st.top() + tem;
                    st.pop();
                }
                st.pop();
                
                int repeat = 0;
                int base = 1;
                while(!st.empty() && st.top().size() == 1 && isdigit(st.top()[0])) {
                    repeat += (st.top()[0] - '0') * base;
                    base *= 10;
                    st.pop();
                }
                string toadd = "";
                while(repeat-- > 0)
                    toadd += tem;
                st.push(toadd);
            }
        }
        string res = "";
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};
