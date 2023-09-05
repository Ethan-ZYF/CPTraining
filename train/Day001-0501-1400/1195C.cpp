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
    vector<vector<i64>> a(3, vector<i64>(n));
    vector<vector<i64>> dp(3, vector<i64>(n));
    // dp[0] = choose first
    // dp[1] = choose second
    // dp[2] = choose none
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    dp[0][0] = a[0][0];
    dp[1][0] = a[1][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                dp[j][i] = max(dp[j][i], dp[k][i - 1] + a[j][i]);
            }
        }
    }
    cout << max({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]}) << '\n';
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