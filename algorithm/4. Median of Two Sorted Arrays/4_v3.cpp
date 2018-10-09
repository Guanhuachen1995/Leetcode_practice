class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res;
        int total = nums1.size() + nums2.size();
        if(total %2 == 1)
            res =  findkth(nums1, nums2, 0, 0, total/2 + 1);
        else
            res =  (findkth(nums1, nums2, 0, 0, total/2) + findkth(nums1, nums2, 0, 0, total/2 + 1))/2.0;

        return res;
    }
    
    double findkth(vector<int>& nums1, vector<int>& nums2, int st1, int st2, int k) {
        if(nums1.size() <= st1)   return nums2[st2+k-1];
        if(nums2.size() <= st2)   return nums1[st1+k-1];
        if(k == 1)  return min(nums1[st1], nums2[st2]);
        
        int n1 = nums1.size()>(st1 + k/2 - 1)?nums1[st1 + k/2 - 1]:INT_MAX;
        int n2 = nums2.size()>(st2 + k/2 - 1)?nums2[st2 + k/2 - 1]:INT_MAX;
        
        if(n1<n2) {
            return findkth(nums1, nums2, st1 + k/2, st2, k - k/2);
        } else
            return findkth(nums1, nums2, st1, st2 + k/2, k - k/2);
    }
};
