from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *
from string import ascii_lowercase

MOD = 10 ** 9 + 7
class Solution:
    def valueAfterKSeconds(self, n: int, k: int) -> int:
        a = [1] * n
        while k:
            b = list(accumulate(a))
            for i in range(n):
                a[i] = b[i] % MOD
            k -= 1
        return a[-1]



if __name__ == "__main__":
    s = Solution()
    # [3, 4, 1, 2, 6]
    # nums = [4, 3, 1, 1, 1, 1, 6]
    nums = [4, 3, 1, 6]
    queries = [[0, 2], [2, 3]]
    print(s.isArraySpecial(nums, queries))
