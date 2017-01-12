class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        result=[]
        self.Parenthesis(result,"",n,n)
        return result
    
    def Parenthesis(self,result,string,l,r):
        if l==0 and r==0:
            result.append(string)
        if(l>0):
            self.Parenthesis(result,string+"(",l-1,r)
        if(r>0)and l<r:
            self.Parenthesis(result,string+")",l,r-1)
