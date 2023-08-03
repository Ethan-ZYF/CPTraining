#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr i64 inf = 1e17;
void solve() {
    int n;
    cin >> n;
    vector<i64> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    i64 ans = inf;

    for (int j = 0; j < n; j++) {
        i64 bimin = inf;
        for (int i = 0; i < j; i++) {
            if (a[i] < a[j]) bimin = min(bimin, b[i]);
        }
        i64 bkmin = inf;
        for (int k = j + 1; k < n; k++) {
            if (a[k] > a[j]) bkmin = min(bkmin, b[k]);
        }
        ans = min(ans, bimin + b[j] + bkmin);
    }
    if (ans == inf) ans = -1;
    cout << ans << '\n';
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