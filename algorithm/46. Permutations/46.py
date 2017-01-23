class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def permuteRecu( result, used, cur, num):
            if len(cur) == len(num):
                result.append(cur + [])
                return
            for i in xrange(len(num)):
                if not used[i]:
                    used[i] = True
                    cur.append(num[i])
                    permuteRecu(result, used, cur, num)
                    cur.pop()
                    used[i] = False
        result = []
        used = [False] * len(nums)
        permuteRecu(result, used, [], nums)
        return result
