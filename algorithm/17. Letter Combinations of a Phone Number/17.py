class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        lookup = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        result=[]
        if(len(digits)<1):
            return result
        result.append("")
        for digit in digits:
            size=len(result)
            for i in xrange(size):
                tem=result[0]
                del result[0]
                for k in lookup[int(digit)]:
                    result.append(tem+k)
        return result
        
