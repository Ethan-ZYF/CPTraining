from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *


class Solution:
    def waysToReachStair(self, k: int) -> int:
        ans = 0
        cur = 1
        for i in range(30):
            diff = cur - k
            can_use = i + 1
            if diff <= i + 1 and diff >= 0:
                ans += comb(can_use, diff)
            cur += 1 << i
        return ans


if __name__ == "__main__":
    sol = Solution()

    for k in range(100):
        print(k, sol.waysToReachStair(k))
        # print()
