from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *


class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans, n = 0, len(nums)
        q = deque(nums)
        while True:
            if len(q) < 2:
                break
            x = q.popleft()
            y = q.popleft()
            

if __name__ == "__main__":
    s = Solution()
