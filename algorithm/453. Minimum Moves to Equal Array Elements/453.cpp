class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int min=nums[0],result=0;
        for(int i=0; i<nums.size(); i++)
        {
            result+=(nums[i]-min);
        }
        return result;
    }
};
