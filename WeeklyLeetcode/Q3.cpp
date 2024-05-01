#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

i64 dp(i64 start, i64 finish) {
    string low = to_string(start);
    string high = to_string(finish);
    int len = high.size();
    low = string(len - low.size(), '0') + low;  // 补前导零，和 high 对齐
    vector memo(len, -1LL);
    auto f = [&](auto&& self, int i, bool limit_low, bool limit_high, bool is_num) -> i64 {
        if (i == len)
            return is_num;
        if (!limit_low && !limit_high && memo[i] != -1)
            return memo[i];

        i64 res = 0;
        if (!is_num && low[i] == '0')
            res += self(self, i + 1, false, true, false);

        int lo = limit_low ? low[i] - '0' : 0;
        int hi = limit_high ? high[i] - '0' : 9;
        int d0 = is_num ? 0 : 1;
        for (int nx = max(d0, lo); nx <= hi; nx++) {
            res += self(self, i + 1, limit_low && nx == lo, limit_high && nx == hi, true);
        }

        if (!limit_low && !limit_high) {
            memo[i] = res;
        }
        return res;
    };
    return f(f, 0, true, true, false);
}

class Solution {
   public:
    long long minEnd(int n, int x) {}
};

int main() {

    Solution sol;
    vector<int> coins = {1, 2, 3, 5, 7, 11, 13, 17, 19, 20, 21, 22, 23, 24, 25};
    int k = 5;
    cout << sol.findKthSmallest(coins, k) << endl;

    return 0;
}