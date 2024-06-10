from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *
from sortedcontainers import SortedList


class Solution:
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        rewardValues.sort()
        a = 1
        for i in rewardValues:
            a |= (a & ((1 << i) - 1)) << i
        return a.bit_length() - 1


if __name__ == "__main__":
    sol = Solution()
    rewardValues = [1, 1, 3, 3]
    print(sol.maxTotalReward(rewardValues))
    rewardValues = [1, 6, 4, 3, 2]
    print(sol.maxTotalReward(rewardValues))
    rewardValues = [2, 14, 13, 15]  # 29
    print(sol.maxTotalReward(rewardValues))
    rewardValues = [6, 13, 9, 19]  # 34
    print(sol.maxTotalReward(rewardValues))
