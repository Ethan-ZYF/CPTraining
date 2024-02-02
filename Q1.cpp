#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

i64 dp(i64 start, i64 finish) {
    string low = bitset<32>(start).to_string();
    string high = bitset<32>(finish).to_string();
    int len = high.size();
    low = string(len - low.size(), '0') + low;
    vector memo(len, vector(2, -1LL));

    auto f = [&](auto&& self, int i, bool lm_lo, bool lm_hi, bool is_num, bool last_one) -> i64 {
        if (i == len)
            return 1;
        if (!lm_lo && !lm_hi && memo[i][last_one] != -1)
            return memo[i][last_one];

        i64 res = 0;

        if (!is_num && low[i] == '0')
            res += self(self, i + 1, lm_lo, lm_hi, false, false);

        int lo = lm_lo ? low[i] - '0' : 0;
        int hi = lm_hi ? high[i] - '0' : 1;
        int d0 = is_num ? 0 : 1;
        for (int nx = max(d0, lo); nx <= hi; nx++) {
            if (last_one && nx == 1)
                continue;
            res += self(self, i + 1, lm_lo && nx == lo, lm_hi && nx == hi, true, nx == 1);
        }

        if (!lm_lo && !lm_hi) {
            memo[i][last_one] = res;
        }
        return res;
    };
    return f(f, 0, true, true, false, false);
}

class Solution {
   public:
    int findIntegers(int n) {
        return dp(0, n);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        Solution sol;
        int n;
        cin >> n;
        cout << sol.findIntegers(n) << '\n';
    }
}