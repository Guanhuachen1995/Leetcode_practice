class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        result=[0]
        for i in range(n):
            curcount=len(result)
            while curcount>0:
                curcount-=1
                curNum=result[curcount]
                curNum+=(1<<i)
                result.append(curNum)
        return result
