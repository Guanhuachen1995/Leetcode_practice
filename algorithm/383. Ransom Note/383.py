class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        m={}
        for i in range(len(magazine)):
            if magazine[i] in m:
                m[magazine[i]]+=1
            else:
                m[magazine[i]]=1
        for i in range(len(ransomNote)):
            if ransomNote[i] not in m:
                return False
            m[ransomNote[i]]-=1
            if m[ransomNote[i]]<0:
                return False
        return True
