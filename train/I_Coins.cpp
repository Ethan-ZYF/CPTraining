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
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<double> dp(1, 1);
    for (int i = 0; i < n; i++) {
        vector<double> ndp(dp.size() + 1);
        for (int j = 0; j < dp.size(); j++) {
            ndp[j] += dp[j] * (1 - a[i]);
            ndp[j + 1] += dp[j] * a[i];
        }
        dp.swap(ndp);
        debug(dp);
    }
    double ans = 0;
    for (int i = (n + 1) / 2; i <= n; i++) {
        ans += dp[i];
    }
    cout << setprecision(10) << ans << '\n';
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