class Solution(object):

    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        def getnext(s):
            i=0
            result=""
            s+="k"
            while i<len(s)-1:
                count=1
                if s[i]==s[i+1]:
                    while s[i]==s[i+1]:
                        count+=1
                        i+=1
                    result+=str(count)+s[i]
                    i+=1
                else:
                    result+="1"+s[i]
                    i+=1
            return result
            
        result="1"
        for i in range(1,n):
            result=getnext(result)
        return result
                    
