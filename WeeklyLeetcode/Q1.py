from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *


class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        ans = 0
        for x in nums:
            if x < k:
                ans += 1
        return ans


if __name__ == "__main__":
    s = Solution()
