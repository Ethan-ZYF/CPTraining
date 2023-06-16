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
    vector<i64> a(n), ps(n + 1);
    for (auto& x : a) cin >> x;
    partial_sum(a.begin(), a.end(), ps.begin() + 1);
    i64 mn = 0, ans = -1e18;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, ps[i] - mn);
        mn = min(mn, ps[i]);
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