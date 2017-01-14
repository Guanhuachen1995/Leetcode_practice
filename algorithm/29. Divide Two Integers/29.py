class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        result, dvd, dvs = 0, abs(dividend), abs(divisor)
        while dvd >= dvs:
            inc = dvs
            i = 0
            while dvd >= inc:
                dvd -= inc
                result += 1 << i
                inc <<= 1
                i += 1

        if dividend > 0 and divisor < 0 or dividend < 0 and divisor > 0:
            result= -result
        else:
            result= result
        if result>2147483647:
            return 2147483647
        else:
            return result
            
