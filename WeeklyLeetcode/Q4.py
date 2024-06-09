from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *


class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nd = [set()]
        nd[0].add(nums[0])
        for x in nums[1:]:
            s = set()
            for y in nd[-1]:
                s.add(x & y)
            s.add(x)
            nd.append(s)
        ans = inf
        for x in nd:
            for y in x:
                ans = min(ans, abs(y - k))
        return ans


if __name__ == "__main__":
    sol = Solution()
    # nums = [1,2,1,2], k = 2
    nums = [3]
    k = 3
    print(sol.minimumDifference(nums, k))
    nums = [0, 3, 6, 1]
    k = 2
    print(sol.minimumDifference(nums, k))
    #     [1,2,4,5] 3
    nums = [1, 2, 4, 5]
    k = 3
    print(sol.minimumDifference(nums, k))
