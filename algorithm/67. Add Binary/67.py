class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        i,j,c=len(a)-1,len(b)-1,0
        s=""
        while i>=0 or j>=0 or c==1:
            if i>=0:
                c += int(a[i])
            i-=1
            if j>=0:
                c +=int(b[j])
            j-=1
            s= str(c%2)+s
            c = c/2
        return s
