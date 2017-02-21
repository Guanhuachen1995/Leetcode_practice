class Solution(object):
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        result=""
        dic = {10:"a", 11:"b", 12:"c", 13:"d", 14:"e", 15:"f"}
        if num==0:
            return '0'
        if num < 0:
            num=num+2**32
        while num>0:
            if(num%16<10):
                result= str(num%16)+result
            else:
                result = dic[num%16] +result
            num=num/16
        return result
