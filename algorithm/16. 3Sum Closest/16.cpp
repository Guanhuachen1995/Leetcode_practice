class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result=0,i=0,min_diff=INT_MAX;
        sort(nums.begin(),nums.end());
        while (i < nums.size()-2)
        {
            if(i==0 || nums[i]!=nums[i-1])
            {
                int j=i+1, k = nums.size()-1;
                while(j<k)
                {
                    int diff=nums[i]+nums[j]+nums[k]-target;
                    if(abs(diff)<min_diff)
                    {
                        min_diff=abs(diff);
                        result= nums[i]+nums[j]+nums[k];
                    }
                    if(diff>0)
                    {
                        k--;
                    }
                    else if(diff<0)
                        j++;
                    else
                        return target;
                }
            }
            i++;
        }
        return result;
    }
};
