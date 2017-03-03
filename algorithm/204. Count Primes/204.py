class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n<=2:
            return 0
        result=1
        passed=[False]*n
        upper = n**0.5
        for i in range(3,n,2):
            if not passed[i]:
                result+=1
                if i>upper:
                    continue
                for j in range(i*i,n,i):
                    passed[j]=True
        return result
        
