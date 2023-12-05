#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif
constexpr i64 INF = 1e18;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    vector<array<i64, 3>> dp(n + 1, {INF, INF, INF});
    dp[0] = {0, 0, 0};
    for (int i = 0; i < n; i++)
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                if (a[i] + x != a[i - 1] + y)
                    dp[i + 1][x] = min(dp[i + 1][x], dp[i][y] + x * b[i]);

    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}