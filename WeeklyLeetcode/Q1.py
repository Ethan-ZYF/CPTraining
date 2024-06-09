from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *


class Solution:
    def minimumChairs(self, s: str) -> int:
        mx = cur = 0
        for c in s:
            if c == 'E':
                cur += 1
            else:
                cur -= 1
            mx = max(mx, cur)
        return mx

if __name__ == "__main__":
    s = Solution()
    x = 18
    print(s.sumOfTheDigitsOfHarshadNumber(x))
