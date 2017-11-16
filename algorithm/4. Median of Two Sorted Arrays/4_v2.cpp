class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n)   return findMedianSortedArrays(nums2, nums1);
        
        int left = 0, right = m, halfLen = (m + n + 1) / 2, i ,j;
        while(left <= right)
        {
            i = (left+right)/2;
            j = halfLen - i;
            if( i < right &&nums2[j-1] > nums1[i] )   left = i + 1;
            else if(i > left && nums1[i-1] > nums2[j])  right = i - 1;
            else
            {
                int maxLeft = 0;
                if (i == 0) { maxLeft = nums2[j-1]; }
                else if (j == 0) { maxLeft = nums1[i-1]; }
                else { maxLeft = max(nums1[i-1], nums2[j-1]); }
                if ( (m + n) % 2 == 1 ) { return maxLeft; }

                int minRight = 0;
                if (i == m) { minRight = nums2[j]; }
                else if (j == n) { minRight = nums1[i]; }
                else { minRight = min(nums2[j], nums1[i]); }

                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};
