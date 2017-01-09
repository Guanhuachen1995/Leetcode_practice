class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums, result, i = sorted(nums),0 , 0
        min_diff = float("inf")
        while i < len(nums) - 2:
            if i == 0 or nums[i] != nums[i - 1]:
                j, k = i + 1, len(nums) - 1
                while j < k:
                    diff = nums[i] + nums[j] + nums[k] - target
                    if abs(diff) < min_diff:
                        result = nums[i] + nums[j] + nums[k]
                        min_diff=abs(diff)
                    if diff>0:
                        k-=1
                    elif diff<0:
                        j+=1
                    else:
                        return target
            i += 1
        return result
