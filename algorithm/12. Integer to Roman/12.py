class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        value=[1000,900,500,400,100,90,50,40,10,9,5,4,1]
        string=["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
        result=""
        for i in xrange(13):
            while num >= value[i]:
                num -= value[i]
                result+=string[i]
            
        return result
