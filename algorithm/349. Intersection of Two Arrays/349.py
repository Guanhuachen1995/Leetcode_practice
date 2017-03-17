class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        result=[]
        for i in nums2:
            if nums1.count(i):
                result.append(i)
            while nums1.count(i)>0:
                nums1.remove(i)
        return result
