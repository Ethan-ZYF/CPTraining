from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *
from string import ascii_lowercase


class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        mp = Counter(nums)
        dummy = ListNode()
        dummy.next = head
        cur = dummy
        while cur.next:
            if mp[cur.next.val]:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return dummy.next


if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,4,5]
    k = 2
    print(s.maximumLength(nums, k))
    nums = [1, 4, 2, 3, 1, 4]
    k = 3
    print(s.maximumLength(nums, k))