from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *


class Solution:
    def medianOfUniquenessArray(self, nums: List[int]) -> int:
        n = len(nums)
        tot = n * (n + 1) // 2
        t = n * (n + 1) // 4 + 1

        def check(x):
            c = 0
            r = 0
            cnt = Counter()
            for l in range(n):
                while r < n and len(cnt) < x:
                    cnt[nums[r]] += 1
                    r += 1
                if len(cnt) == x:
                    c += n - r + 1
                cnt[nums[l]] -= 1
                if cnt[nums[l]] == 0:
                    del cnt[nums[l]]
            return c

        L, R = 0, n + 1
        while L + 1 < R:
            mid = (L + R) // 2
            if check(mid) < t:
                R = mid
            else:
                L = mid
        return L


if __name__ == "__main__":
    sol = Solution()
    nums = [1, 2, 3]
    print(sol.medianOfUniquenessArray(nums))
    print()

    nums = [3, 4, 3, 4, 5]
    print(sol.medianOfUniquenessArray(nums))
