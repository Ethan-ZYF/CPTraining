from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *


class Solution:
    def getSmallestString(self, s: str) -> str:
        n = len(s)
        s = list([int(x) for x in s])
        for i in range(n - 1):
            if s[i] % 2 == s[i + 1] % 2 and s[i] > s[i + 1]:
                s[i], s[i + 1] = s[i + 1], s[i]
                break
        return "".join([str(x) for x in s])

if __name__ == "__main__":
    s = Solution()
    x = 18
    print(s.sumOfTheDigitsOfHarshadNumber(x))
