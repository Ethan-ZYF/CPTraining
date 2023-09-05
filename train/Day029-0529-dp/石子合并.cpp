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
    vector<int> a(n), s(n + 1);
    for (auto& x : a) cin >> x;
    partial_sum(a.begin(), a.end(), s.begin() + 1);
    vector dp(n, vector(n, INF));
    for (int i = 0; i < n; i++) dp[i][i] = 0;

    for (int length = 1; length < n; length++) {
        for (int i = 0; i + length < n; i++) {
            int j = i + length;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j + 1] - s[i]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
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