class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> dic;
        vector<int> result;
        for(auto i : nums1)
        {
            dic[i]++;
        }
        for (auto i:nums2)
        {
            if(dic[i]>0)
            {
                result.push_back(i);
                dic[i]--;
            }
        }
        return result;
    }
};
