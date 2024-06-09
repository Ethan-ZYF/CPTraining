from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *
from math import gcd, lcm


class Solution:
    def numberOfPairs(self, nums1, nums2, k):
        c1 = Counter(x // k for x in nums1 if x % k == 0)
        c2 = Counter(nums2)
        mx = max(c1.keys()) + 1
        ans = 0
        for x, v in c2.items():
            res = 0
            for y in range(x, mx, x):
                res += c1[y]
            ans += res * v
        return ans
            


if __name__ == "__main__":
    s = Solution()
    nums = [13, 23, 12]
    print(s.sumDigitDifferences(nums))
