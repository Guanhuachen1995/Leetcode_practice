class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w=sqrt(area);
        while(area%w!=0)
            w--;
        return vector<int>{area/w,w};
    }
};
