class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int p1 = 0, p2 = 0, min1 = INT_MAX, sum = 0;
        if (nums.size() == 0)
            return 0;
        
        while(p2 < nums.size())
        {
            sum += nums[p2++];
            while(sum >= s)
            {
                min1 = min(min1, p2 - p1 );
                sum -= nums[p1++];
            }
        }
        return min1 == INT_MAX?0:min1;
    }
};
