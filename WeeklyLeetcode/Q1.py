from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *


class Solution:
    def numberOfChild(self, n: int, k: int) -> int:
        i = 0
        di = 1
        while k:
            i += di
            if i == n - 1:
                di = -1
            if i == 0:
                di = 1
            k -= 1
        return i


if __name__ == "__main__":
    s = Solution()
    x = 18
    print(s.sumOfTheDigitsOfHarshadNumber(x))
