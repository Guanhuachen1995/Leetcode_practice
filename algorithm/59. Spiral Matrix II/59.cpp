class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        
        int layer = (n + 1) / 2, tem = 1;
        for (int i = 0; i < layer; i++)
        {
            //from top-left to top-right
            for(int j = i; j < n - i; j++)
            {
                result[i][j] = tem++;
            }
            //from left-top to left-bottom
            for(int j = i + 1; j < n -i; j++)
            {
                result[j][n - 1 - i] = tem++;
            }
            
            //from bottom-right to bottom-left
            if(n - 1 - i > i)
            {
                for(int j = n - 1 - i -1; j >= i; j--)
                {
                    result[n - 1 -i][j] = tem++;
                }
                for(int j = n - 1 - i -1; j > i; j--)
                {
                    result[j][i] = tem++;
                }
            }
        }
        return result;
    }
};
