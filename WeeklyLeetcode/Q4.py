from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *
from math import comb


class Solution:
    def minimumDiameterAfterMerge(self, edges1: List[List[int]], edges2: List[List[int]]) -> int:
        def diameter(n, edges):
            g = defaultdict(list)
            for u, v in edges:
                g[u].append(v)
                g[v].append(u)
            diam = 0

            def dfs(u, p):
                nonlocal diam
                h = []
                for v in g[u]:
                    if v == p:
                        continue
                    h.append(dfs(v, u))
                h.sort()
                if len(h) == 0:
                    return 1
                if len(h) == 1:
                    diam = max(diam, h[0])
                    return h[0] + 1
                diam = max(diam, h[-1] + h[-2])
                return h[-1] + 1

            dfs(0, -1)
            return diam

        n1 = len(edges1) + 1
        n2 = len(edges2) + 1
        diam1 = diameter(n1, edges1)
        diam2 = diameter(n2, edges2)
        level1 = (diam1 + 1) // 2
        level2 = (diam2 + 1) // 2
        # print(level1, level2)
        # print(diam1, diam2)
        return max(level1 + level2 + 1, max(diam1, diam2))


if __name__ == "__main__":
    s = Solution()
    # [[0,1]] [[0, 1], [1, 2]]
    edges1 = [[0, 1]]
    edges2 = [[0, 1], [1, 2]]
    print(s.minimumDiameterAfterMerge(edges1, edges2))
