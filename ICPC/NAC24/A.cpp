#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr int MX = 5e6 + 5;
constexpr int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    vector<array<int, MX>> dp(n + 1);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < MX; j++) {
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MX; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i]);
            if (j + b[i] < MX) {
                dp[i + 1][j + b[i]] = min(dp[i + 1][j + b[i]], dp[i][j]);
            }
        }
    }
    int ans = inf;
    for (int j = 0; j < MX; j++) {
        ans = min(ans, max(j, dp[n][j]));
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