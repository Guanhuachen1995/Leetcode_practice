class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.empty() || matrix[0].empty())
            return ret;
        
        int m = matrix.size();
        int n = matrix[0].size();
        int layer = (min(m,n)+1) / 2;
        for(int i = 0; i < layer; i ++)
        {
            //row i: top-left --> top-right
            for(int j = i; j < n-i; j ++)
                ret.push_back(matrix[i][j]);
                
            //col n-1-i: top-right --> bottom-right
            for(int j = i+1; j < m-i; j ++)
                ret.push_back(matrix[j][n-1-i]);
                
            //row m-1-i: bottom-right --> bottom-left
            if(m-1-i > i)
            {
                for(int j = n-1-i-1; j >= i; j --)
                    ret.push_back(matrix[m-1-i][j]);
            }
                
            //col i: bottom-left --> top-left
            if(n-1-i > i)
            {
                for(int j = m-1-i-1; j > i; j --)
                    ret.push_back(matrix[j][i]);
            }
        }
        return ret;
    }
};
