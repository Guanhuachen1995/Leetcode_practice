class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        row1=['q', 'w', 'e', 'r', 't', 'y','u', 'i', 'o', 'p'];
        row2=['a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l']; 
        row3=[ 'z', 'x', 'c', 'v', 'b' ,'n', 'm'];
        row=[row1,row2,row3]
        result=[]
        rownum=0
        for i in range(len(words)):
            for j in range(3):
                if row[j].count((words[i][0].lower()))>0:
                    rownum=j
            result.append(words[i])
            for j in range(1,len(words[i])):
                if row[rownum].count(words[i][j].lower())==0:
                    result.pop()
                    break
        
        return result
