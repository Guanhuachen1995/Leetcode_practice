class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int amount= nums1.size() + nums2.size();
        double median;
        int i=0 ,  j = 0;
        vector<int> tem;
        while ( i < nums1.size() && j < nums2.size() )
        {
        	if (nums1[i] < nums2[j])
        		tem.push_back(nums1[i++]);
        	else
        		tem.push_back(nums2[j++]);
        }
        if ( i == nums1.size()) 
        {
        	while(j < nums2.size())
        		tem.push_back(nums2[j++]);
        }
        else
        {
        	while(i < nums1.size())
        		tem.push_back(nums1[i++]);
        }
        if (amount %2 ==1)
        	median = tem[ amount/2 ];
        else
        	median = ((double) tem[amount/2] + (double)tem[amount/2 -1 ])/2 ;
        return median ;
    }
};