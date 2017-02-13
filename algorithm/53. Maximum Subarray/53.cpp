public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[nums.size()-1];
        int maxSum= sum;
        for (int i = nums.size()-2;i>=0;i--)
        {
            sum = max(nums[i], sum + nums[i]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
