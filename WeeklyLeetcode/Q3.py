from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *
from math import gcd, lcm


class Solution:
    def minEnd(self, n: int, x: int) -> int:
        n -= 1
        # n 的第j位是 x 的第i位
        i = j = 0
        while n >> j:
            if x >> i & 1 == 0:
                bit = n >> j & 1
                x |= bit << i
                j += 1
            i += 1
        return x


if __name__ == "__main__":
    s = Solution()
    # n = 3, x = 4
    print(s.minEnd(3, 4))
    print(s.minEnd(3, 2))
    # 3 2: 6
    print(s.minEnd(2, 4))
    # 5
