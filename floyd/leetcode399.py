class Solution(object):
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        from collections import defaultdict
        graph = defaultdict(int)
        vertices = set()

        for i in range(len(equations)):
            a, b = equations[i]
            graph[(a, b)] = values[i]
            graph[(b, a)] = 1 / values[i]
            vertices.add(a)
            vertices.add(b)
        # print(graph)
        arr = list(vertices)
        for i in arr:
            for j in arr:
                for k in arr:
                    if graph[(j, i)] and graph[(i, k)]:
                        graph[(j, k)] = graph[(j, i)] * graph[(i, k)]
        ret = []
        # print(graph)
        for i, j in queries:
            if graph[(i, j)]:
                ret.append(graph[(i, j)])
            else:
                ret.append(-1)
        return ret
             