class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int tem=0;
        for(int i : nums)
        {
            tem^=i;
        }
        tem=tem&(~(tem-1));
        vector<int> result(2,0);
        for(int i : nums)
        {
            if((i & tem)==0)
                result[0]^=i;
            else
                result[1]^=i;
        }
        return result;
    }
};
