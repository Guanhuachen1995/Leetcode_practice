class Solution(object):
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num==1:
            return False
        tem,result=2,1
        while tem*tem<=num:
            if num%tem==0:
                result+=tem
                if num/tem!=tem:
                    result+=num/tem
            tem+=1
        return result==num
