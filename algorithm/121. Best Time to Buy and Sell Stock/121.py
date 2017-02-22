class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        minprice, maxpro=2147483647,0
        for i in range(len(prices)):
            minprice = min(minprice, prices[i])
            maxpro = max(maxpro, prices[i]-minprice)
        return maxpro            
