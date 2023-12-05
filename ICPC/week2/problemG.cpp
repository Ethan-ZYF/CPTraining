#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector dp(n, vector(n, array{INF, INF}));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i][i] = {0, 0};
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i + 1 < n) {
                dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][0] + (a[i] != a[i + 1]));
                dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][1] + (a[i] != a[j]));
            }
            if (j > 0) {
                dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + (a[j] != a[i]));
                dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + (a[j] != a[j - 1]));
            }
        }
    }
    cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << '\n';
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