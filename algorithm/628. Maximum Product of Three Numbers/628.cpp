class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int result1,result2;
        sort(nums.begin(),nums.end());
        result1 = nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
        result2 = nums[nums.size()-1]*nums[0]*nums[1];
        return result1>result2?result1:result2;
        
    }
};
