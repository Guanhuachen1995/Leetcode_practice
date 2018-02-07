class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        char maxSize = '0';
        for (int j = 0; j < cols; ++j)
			if (matrix[0][j] == '1') {
				maxSize = '1';
				break;
			}
        for (int i = 1; i < rows; ++i) {
            maxSize = max(maxSize, matrix[i][0]);
            for (int j = 1; j < cols; ++j)
                if (matrix[i][j] == '1') {
                    matrix[i][j] = min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1])) + 1;
                    maxSize = max(maxSize, matrix[i][j]);
                }
        }
        return (maxSize - '0') * (maxSize - '0');
    }
};
