from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *
from string import ascii_lowercase


class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        merged = []
        s, e = meetings[0]
        for x, y in meetings[1:]:
            if x <= e:
                e = max(e, y)
            else:
                merged.append([s, e])
                s, e = x, y
        merged.append([s, e])
        for s, e in merged:
            days -= e - s + 1
        return days



if __name__ == "__main__":
    s = Solution()
    # [3, 4, 1, 2, 6]
    # nums = [4, 3, 1, 1, 1, 1, 6]
    nums = [4, 3, 1, 6]
    queries = [[0, 2], [2, 3]]
    print(s.isArraySpecial(nums, queries))
