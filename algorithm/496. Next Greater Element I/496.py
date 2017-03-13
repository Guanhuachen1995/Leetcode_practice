class Solution(object):
    def nextGreaterElement(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """
        m={}
        s=[]
        ans=[]
        for i in nums:
            while len(s) and s[-1]<i:
                m[s.pop()]=i
            s.append(i)
        for i in findNums:
            ans.append(m.get(i, -1))
        return ans
