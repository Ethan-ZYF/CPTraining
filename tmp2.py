from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *


class Solution:
    def countOfPairs(self, n: int, x: int, y: int) -> List[int]:
        # Ensure x is smaller than y for simplicity
        if x > y:
            x, y = y, x

        result = [0] * n

        # For k = 1, we count all adjacent pairs plus the shortcut
        result[0] = 2 * (n - 1)
        if abs(x - y) > 1:  # Add the shortcut pair only if it's not adjacent
            result[0] += 2

        for k in range(1, n):
            total_pairs = 0
            # Count pairs in the linear part of the street
            total_pairs += max(0, (n - k) * 2)

            # Count additional pairs using the shortcut
            if k < y - x:
                extra_pairs = min(x, k) + min(n - y + 1, k)
                total_pairs += extra_pairs * 2

            result[k] = total_pairs

        return result


if __name__ == "__main__":
    s = Solution()
