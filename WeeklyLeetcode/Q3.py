from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *
from math import gcd, lcm


class Solution:
    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        # Sort the cuts in descending order
        horizontalCut.sort(reverse=True)
        verticalCut.sort(reverse=True)

        # Initialize pointers and total cost
        i, j = 0, 0
        total_cost = 0

        # While there are still pieces larger than 1x1
        while i < len(horizontalCut) or j < len(verticalCut):
            # If both horizontal and vertical cuts are available
            if i < len(horizontalCut) and j < len(verticalCut):
                if horizontalCut[i] > verticalCut[j]:
                    total_cost += horizontalCut[i] * (j + 1)
                    i += 1
                else:
                    total_cost += verticalCut[j] * (i + 1)
                    j += 1
            # If only horizontal cuts are available
            elif i < len(horizontalCut):
                total_cost += horizontalCut[i] * (j + 1)
                i += 1
            # If only vertical cuts are available
            elif j < len(verticalCut):
                total_cost += verticalCut[j] * (i + 1)
                j += 1

        return total_cost


if __name__ == "__main__":
    s = Solution()
    # 3
    # 2
    # [1, 3]
    # [5]
    m = 3
    n = 4
    horizontalCut = [1, 100]
    verticalCut = [1, 1, 100]
    print(s.minimumCost(m, n, horizontalCut, verticalCut))
