class Solution(object):
    def dicesProbability(self, n):
        """
        :type n: int
        :rtype: List[float]
        """
        dp = [0.0] * (6 * n + 1)  # 最终的答案范围是从 n 到 6 * n
        for i in range(1, 7):
            dp[i] = 1 / 6.0  # 初始化边界case， 即 n = 1 
        for i in range(2, n + 1): # 第一层循环遍历扔几次骰子
            tmp = [0.0] * (6 * i + 1)  # 将本次的结果保留在临时数组中
            for j in range(1, 6 * (i - 1) + 1): # 遍历上一次结果的所有值
                for k in range(1, 7): # 和本次扔骰子的所有可能结果相乘，并存储到临时数组中
                    tmp[j + k] += dp[j] * 1 / 6  # 核心转移公式，需要自己思考
            dp = tmp
        # print(dp)
        return dp[n:]