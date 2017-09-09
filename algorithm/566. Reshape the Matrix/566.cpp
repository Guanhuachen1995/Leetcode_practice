class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size() == 0)
            return nums;
        vector<vector<int>> result(r);
        int a = nums.size();
        int b = nums[0].size();
        if(a*b != r*c)
            return nums;
        for(int i = 0; i < a; i++)
        {
            for(int j = 0; j < b; j++)
            {
                int k = i * b + j;
                result[k/c].push_back(nums[i][j]);
            }
        }
        return result;
    }
};
