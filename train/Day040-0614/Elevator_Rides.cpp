#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }

    vector<array<int, 2>> dp(1 << n, {n + 1, 0});
    dp[0] = {0, 0};
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                continue;
            }
            int w = dp[mask][1] + a[i];
            int r = dp[mask][0];
            if (w > m) {
                r++;
                w = a[i];
            }
            dp[mask | (1 << i)] = min(dp[mask | (1 << i)], {r, w});
        }
    }
    int ans = dp[(1 << n) - 1][0];
    if (dp[(1 << n) - 1][1] > 0) {
        ans++;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}