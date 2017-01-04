class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        map={}
        lastbit, max =-1 , 0
        for i in xrange(len(s)):
        	if map.has_key(s[i])== True and lastbit < map[s[i]]:
        		lastbit=map[s[i]]
        	if i - lastbit > max:
        		max = i - lastbit
        	map[s[i]]=i

        return max