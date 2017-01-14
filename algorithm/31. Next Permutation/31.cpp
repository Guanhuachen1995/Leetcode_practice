class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = nums.size() - 1;
        while(nums[index] <= nums[index-1]) {
            --index;
        }
        if(index == 0) {
            sort(nums.begin(), nums.end());
            return ;
        }
        int exchangeIndex;
        for(int i = nums.size()-1; i >= index; i--){
            if(nums[i] > nums[index-1]){
                exchangeIndex = i;
                break;
            }
        }
        swap(nums[index-1],nums[exchangeIndex]);
        sort(nums.begin()+index, nums.end());    
    }
};
