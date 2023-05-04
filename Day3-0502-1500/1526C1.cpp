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
    vector<i64> dp(n + 1, -1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            if (dp[j - 1] + a[i - 1] >= 0)
                dp[j] = max(dp[j], dp[j - 1] + a[i - 1]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] >= 0) ans = i;
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