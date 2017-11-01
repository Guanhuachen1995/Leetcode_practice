class Solution {
public:
    string simplifyPath(string path) {
        int start = 0;
        stack<string> st;
        for(int i = 1; i < path.size(); i++)
        {
            if(path[i] == '/' || i == path.size() - 1)
            {
                string tem;
                if(path[i] != '/')
                    tem =path.substr(start, i - start + 1);
                else
                    tem =path.substr(start, i - start);
                cout<< tem;
                if(tem == "/..")
                {
                    if(!st.empty())
                        st.pop();
                }
                else if(tem == "/.")
                {}
                else if(tem == "/")
                {}
                else
                    st.push(tem);
                start = i;
            }
        }
        string res = "";
        while(!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        return res == ""?"/":res;
        
    }
};
