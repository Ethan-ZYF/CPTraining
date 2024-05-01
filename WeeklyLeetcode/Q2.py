from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *
from string import ascii_lowercase


class Solution:
    def minimumAddedInteger(self, nums1: List[int], nums2: List[int]) -> int:
        nums1.sort()
        nums2.sort()
        # print(nums1, nums2)
        def check(x):
            cnt = 0
            i = j = 0
            while i < len(nums1) and j < len(nums2):
                if nums1[i] + x == nums2[j]:
                    i += 1
                    j += 1
                else:
                    cnt += 1
                    i += 1
            return cnt <= 2
        for i in range(-1000, 1001):
            if check(i):
                return i
        return -1

if __name__ == "__main__":
    s = Solution()
    # [9, 4, 3, 9, 4]
    # [7, 8, 8]
    print(s.minimumAddedInteger(nums1=[9, 4, 3, 9, 4], nums2=[7, 8, 8]))