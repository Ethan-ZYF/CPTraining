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
    vector<array<i64, 3>> a(n);
    for (auto& [l, r, x] : a) {
        cin >> l >> r >> x;
    }
    sort(a.begin(), a.end(), [](auto& a, auto& b) { return a[1] < b[1]; });
    map<int, i64> dp;
    dp[0] = 0;
    for (auto& [l, r, x] : a) {
        debug(dp);
        auto it = dp.lower_bound(l);
        it--;
        i64 nr = r;
        i64 nx = it->second + x;
        if (nx > dp.rbegin()->second) {
            dp[nr] = nx;
        }
    }
    i64 ans = 0;
    for (auto& [r, x] : dp) {
        ans = max(ans, x);
    }
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