class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        sums = 0
        for i in nums:
            sums += i
        if sums % 2 != 0:
            return False
        target = sums / 2
        dp = [0] * (target + 1)
        dp[0] =  1

        for i in range(len(nums)):
            for j in range(target, nums[i] - 1, -1):
                dp[j] += dp[j - nums[i]]
                # print(dp[j], j)
        # print(dp)
        return True if dp[target] else False