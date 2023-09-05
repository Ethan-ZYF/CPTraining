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
    vector<i64> a(n);
    for (auto& x : a) cin >> x;

    vector dp(n, vector(n, 0LL));
    for (int l = n - 1; l >= 0; l--) {
        dp[l][l] = a[l];
        for (int r = l + 1; r < n; r++) {
            dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
        }
    }
    i64 diff = dp[0][n - 1];
    i64 sum = accumulate(a.begin(), a.end(), 0LL);
    debug(diff, sum);
    cout << (sum + diff) / 2 << endl;
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