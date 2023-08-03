from typing import *


class Solution:
    def maxIncreasingGroups(self, cnt: List[int]) -> int:
        cnt.sort()
        res = 0
        s = 0
        for x in cnt:
            s += x
            if (res + 1) * (res + 2) // 2 <= s:
                res += 1
        return res


if __name__ == "__main__":
    s = Solution()

    nums = [1, 7, 7, 1]  # 3
    print(s.maxIncreasingGroups(nums))
    nums = [2, 2, 2]  # 3
    print(s.maxIncreasingGroups(nums))
    nums = [1, 1, 5]  # 2
    print(s.maxIncreasingGroups(nums))
    nums = [1, 9, 10, 1, 5]  # 4
    print(s.maxIncreasingGroups(nums))
    nums = [1, 1, 1]  # 2
    print(s.maxIncreasingGroups(nums))
