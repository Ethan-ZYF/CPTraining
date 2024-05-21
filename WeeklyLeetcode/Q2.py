from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *
from string import ascii_lowercase


class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        ans = []
        n = len(nums)
        segs = [0] * n
        for i in range(n):
            nums[i] -= i
            nums[i] %= 2
        l = 0
        for r in range(n):
            if nums[r] == nums[l]:
                segs[r] = l
            else:
                l = r
                segs[r] = l
        # print(nums)
        # print(segs)
        for l, r in queries:
            ll = segs[r]
            ans.append(ll <= l)
        return ans


if __name__ == "__main__":
    s = Solution()
    # [3, 4, 1, 2, 6]
    # nums = [4, 3, 1, 1, 1, 1, 6]
    nums = [4, 3, 1, 6]
    queries = [[0, 2], [2, 3]]
    print(s.isArraySpecial(nums, queries))
