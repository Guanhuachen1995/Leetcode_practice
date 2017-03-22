class Solution(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        x=abs(num)
        res=""
        while True:
            tem=x%7
            res=str(tem)+res
            x/=7
            if x==0:
                break
        if num<0:
            return ("-"+res)
        return res
