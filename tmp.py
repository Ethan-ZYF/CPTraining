from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *

class Solution:
    def countOfPairs(self, n: int, x: int, y: int) -> List[int]:
        if x > y:
            x, y = y, x
        ans = [0] * n
        m = y - x + 1
        l, r = x - 1, n - y
        acc = [0] * (n + 1)
        if abs(x - y) <= 1:
            for i in range(n):
                ans[n - i - 1] = i * 2
        else:
            nn = n - (y - x - 1)
            for i in range(nn):
                ans[i] = (nn - i - 1) * 2
            for i in range(1, m // 2 + 1):
                if i * 2 == m:
                    ans[i - 1] += m
                else:
                    ans[i - 1] += m * 2
            ans[0] -= 2
            for i in range(1, m // 2 + 1):
                acc[i] += 4
                acc[i + l] -= 2
                acc[i + r] -= 2
                if (i + 1) * 2 < m:
                    acc[i + 1] += 4
                    acc[i + l + 1] -= 2
                    acc[i + r + 1] -= 2
        tot = 0
        for i in range(n):
            tot += acc[i]
            ans[i] += tot
        return ans

if __name__ == "__main__":
    s = Solution()
    print(s.countOfPairs(3, 1, 3))
    print(s.countOfPairs(5, 2, 4))
    print(s.countOfPairs(4, 1, 1))
