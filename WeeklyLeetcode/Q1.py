from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *


class Solution:
    def isArraySpecial(self, nums: List[int]) -> bool:
        ans = True
        for x, y in paiwise(nums):
            if x % 2 == y % 2:
                ans = False
                break
        return ans

if __name__ == "__main__":
    s = Solution()
    x = 18
    print(s.sumOfTheDigitsOfHarshadNumber(x))
