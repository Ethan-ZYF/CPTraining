#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    if (n == 1) {
        int left = a[0] - 1, right = k - a[0];
        right = max(right, 0);
        cout << left + right << "\n";
        return;
    }
    i64 ans = 0;
    auto [i1, i2] = minmax_element(a.begin(), a.end());
    int lo = *i1, hi = *i2;
    for (int i = 1; i < n; i++) {
        int l = a[i - 1], r = a[i];
        if (r < l) swap(l, r);
        ans += r - l;
    }
    debug(ans);
    debug(lo, hi);
    int t1 = lo - 1, t2 = k - hi;
    t2 = max(t2, 0);
    int t3 = a[0] - 1, t4 = max(k - a[n - 1], 0);
    int t5 = max(k - a[0], 0), t6 = a[n - 1] - 1;
    int tleft = min({2 * t1, t3, t6});
    int tright = min({2 * t2, t4, t5});
    debug(tleft, tright);
    ans += tleft + tright;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}