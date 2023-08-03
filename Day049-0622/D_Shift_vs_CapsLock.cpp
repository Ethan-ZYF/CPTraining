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
    i64 x, y, z;
    cin >> x >> y >> z;
    string s;
    cin >> s;
    int n = s.size();
    vector<array<i64, 2>> dp(n + 1, {INF, INF});
    dp[0][0] = 0;
    dp[0][1] = z;
    for (int i = 0; i < n; i++) {
        // lower
        if (s[i] == 'a') {
            // 'a'
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + x);
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + z + x);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + y);
        } else {
            // 'A'
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + x);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + z + x);
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + y);
        }
        dp[i + 1][0] = min(dp[i + 1][0], dp[i + 1][1] + z);
        dp[i + 1][1] = min(dp[i + 1][1], dp[i + 1][0] + z);
        // upper
        debug(dp[i + 1]);
    }
    cout << min(dp[n][0], dp[n][1]) << '\n';
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