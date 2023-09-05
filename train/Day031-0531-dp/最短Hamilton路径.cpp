#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin >> n;
    vector g(n, vector(n, 0LL));
    for (int i = 0; i < n; i++) {
        for (int j = 0, x; j < n; j++) {
            cin >> g[i][j];
        }
    }
    vector dp(n, vector(1 << n, numeric_limits<i64>::max() / 2));
    dp[0][1] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) {
                for (int j = 0; j < n; j++) {
                    if (mask >> j & 1) {
                        dp[i][mask] = min(dp[i][mask], dp[j][mask ^ (1 << i)] + g[j][i]);
                    }
                }
            }
        }
    }
    cout << dp.back().back() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}