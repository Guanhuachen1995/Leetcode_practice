class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        double ans=-1,N=p.size();
        for (int i=0; i<N-2; ++i)
            for (int j=1; j<N-1; ++j)
                for (int k=2; k<N; ++k)
                    ans=max(ans,area(p[i][0],p[i][1],p[j][0],p[j][1],p[k][0],p[k][1]));
        return ans;
    }
    
    double area(int x1, int y1, int x2, int y2, int x3, int y3){
        return abs(0.5*( (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1) ));
    }
};
