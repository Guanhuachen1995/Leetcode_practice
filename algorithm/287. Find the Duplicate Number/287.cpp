class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while(i < j) {
            int mid = i + (j - i)/2;
            int count = 0;
            for(auto k:nums) {
                if(k <= mid)
                    count++;
            }
            if(count <= mid)
                i = mid + 1;
            else
                j = mid;
        }
        return i;
    }
};
