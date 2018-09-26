class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        heights.push_back(0);
        vector<int> st;
        for(int i = 0; i < heights.size(); i++) {
            while(st.size() > 0 && heights[st.back()] >= heights[i]) {
                int h = heights[st.back()];
                st.pop_back();
                
                int l = st.size()>0?st.back():-1;
                int len = i - l - 1;
                if(h*len > res)
                    res = h*len;
            }
            st.push_back(i);
        }
        return res;
    }
};
