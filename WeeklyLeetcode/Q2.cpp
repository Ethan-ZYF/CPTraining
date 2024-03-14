#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif
class Solution {
   public:
    int minOperations(vector<int>& nums, int k) {
        multiset<i64> s;
        for (int x : nums) {
            s.insert(x);
        }
        int ans = 0;
        while (true) {
            if (s.size() < 2) {
                break;
            }
            i64 x = *s.begin();
            s.erase(s.begin());
            i64 y = *s.begin();
            s.erase(s.begin());
            if (x >= k and y >= k) {
                break;
            }
            i64 z = x * 2 + y;
            s.insert(z);
            ans++;
        }
        return ans;
    }
};

int main() {
    // [999999999,999999999,999999999]
    // 1000000000
    vector<int> nums = {999999999, 999999999, 999999999};
    int k = 1000000000;
    Solution sol;
    cout << sol.minOperations(nums, k) << endl;
    return 0;
}