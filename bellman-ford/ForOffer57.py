class Solution(object):
    def findContinuousSequence(self, target):
        """
        :type target: int
        :rtype: List[List[int]]
        """
        stack = []
        ret = []
        cur = 0
        for i in range(1, target):
            while cur > target:
                cur -= stack.pop(0)
           
            if cur == target:
                ret.append(list(stack))
            stack.append(i)
            cur += i
        return ret   
