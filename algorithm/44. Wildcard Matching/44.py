class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        isstar=False
        s1,p1=0,0
        while s1<len(s) and (p1<len(p) or isstar):
            if s[s1]==p[p1] or p[p1]=='?':
                s1+=1
                p1+=1
            elif p[p1]=='*':
                isstar=True
                p1+=1
                if p1>=len(p):
                    return True
                ss=s1
                pp=p1
            else:
                if not isstar:
                    return False
                p1=pp
                s1=ss+1
        if s1>=len(s):
            if p1>=len(p):
                return True
            while p[p1]=='*':
                p1+=1
            if p1>=len(p):
                return True
        return False
