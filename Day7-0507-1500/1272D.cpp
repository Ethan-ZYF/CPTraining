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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<array<int, 2>> dp(n, {1, 1});
    // dp[i][0]: deleted, dp[i][1]: not yet deleted
    for (int i = 1; i < n; i++) {
        if (i == 1) {
            if (a[i] > a[i - 1]) {
                dp[i][1] = dp[i - 1][1] + 1;
                dp[i][0] = dp[i - 1][0] + 1;
            }
        } else {
            if (a[i] > a[i - 1]) {
                dp[i][1] = dp[i - 1][1] + 1;
                dp[i][0] = dp[i - 1][0] + 1;
            }
            if (a[i] > a[i - 2]) {
                dp[i][0] = max(dp[i][0], dp[i - 2][1] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans << '\n';
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