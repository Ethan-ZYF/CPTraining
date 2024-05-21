#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    for (auto& x : a)
        cin >> x;

    vector<i64> cnt(n + 1, 0);
    for (i64 i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    vector<i64> dp(n + 1);
    for (i64 k = n; k >= 1; k--) {
        i64 c = 0;
        for (i64 bs = k; bs <= n; bs += k) {
            c += cnt[bs];
        }
        dp[k] = c * (c - 1) / 2;
        for (i64 bs = k + k; bs <= n; bs += k) {
            dp[k] -= dp[bs];
        }
    }
    debug(dp);
    i64 ans = 0;
    vector<bool> f(n + 1);
    for (i64 i = 1; i <= n; i++) {
        if (cnt[i]) {
            for (i64 j = i; j <= n; j += i) {
                f[j] = true;
            }
        }
    }
    debug(f);
    for (i64 i = 1; i <= n; i++) {
        if (!f[i]) {
            ans += dp[i];
        }
    }
    cout << ans << '\n';
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