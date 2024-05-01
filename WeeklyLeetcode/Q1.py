from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *

class Solution:
    def addedInteger(self, nums1: List[int], nums2: List[int]) -> int:
        nums1.sort()
        nums2.sort()
        return nums2[0] - nums1[0]

if __name__ == "__main__":
    s = Solution()
    x = 18
    print(s.sumOfTheDigitsOfHarshadNumber(x))
