from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *
from math import gcd, lcm


class Solution:
    def maxTotalReward(self, a):
        mx = max(a)

        f = [0] * (mx * 2 + 1)

        a.sort()

        ans = 0
        for r in a:
            for j in range(r * 2 + 1):
                if r <= j < 2 * r:
                    f[j] = max(f[j], f[j - r] + r)
                    ans = max(ans, f[j])
        return ans


if __name__ == "__main__":
    s = Solution()
    nums = [13, 23, 12]
    print(s.sumDigitDifferences(nums))
