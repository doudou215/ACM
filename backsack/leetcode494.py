# 01背包问题是选或者不选，但本题是必须选，是选+还是选-。先将本问题转换为01背包问题。
# 假设所有符号为+的元素和为x，符号为-的元素和的绝对值是y。
# 我们想要的 S = 正数和 - 负数和 = x - y
# 而已知x与y的和是数组总和：x + y = sum
# 可以求出 x = (S + sum) / 2 = target
# 也就是我们要从nums数组里选出几个数，令其和为target
# 于是就转化成了求容量为target的01背包问题 =>要装满容量为target的背包，有几种方案

class Solution(object):
    def findTargetSumWays(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        sumAll = sum(nums)
        # print(sumAll)
        if target > sumAll or (sumAll + target) % 2:
            return 0
        target = (sumAll + target) / 2 # 这里要注意保证sumAll + target一定是个偶数
        
        n = len(nums)
        dp = [0] * (target + 1) # dp[i]代表刚好装满i个背包有多少种方式
        dp[0] = 1 # 注意边界
        for i in range(n):
            for j in range(target, nums[i] - 1, -1):
                dp[j] += dp[j - nums[i]]
            # print(dp[j])
        return dp[-1]