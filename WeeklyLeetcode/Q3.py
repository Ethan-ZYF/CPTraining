from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *
from math import gcd, lcm


class Solution:
    def sumDigitDifferences(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        cnt = [[0] * 10 for _ in range(10)]
        for x in nums:
            i = 0
            while x:
                cnt[i][x % 10] += 1
                x //= 10
                i += 1
        for i in range(10):
            s = sum(cnt[i])
            for x in cnt[i]:
                ans += x * (s - x)
                s -= x
        return ans


if __name__ == "__main__":
    s = Solution()
    nums = [13, 23, 12]
    print(s.sumDigitDifferences(nums))
