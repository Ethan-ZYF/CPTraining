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
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<i64>> dp(n + 1, vector<i64>(n + 1, -1e9));
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j];
            if (dp[i - 1][j - 1] + a[i - 1] < 0) continue;
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i - 1]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[n][i] >= 0) ans = i;
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