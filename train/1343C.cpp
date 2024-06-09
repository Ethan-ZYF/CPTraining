#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int cur = a[0] / abs(a[0]);
    int mx = a[0];
    i64 ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] / abs(a[i]) == cur) {
            mx = max(mx, a[i]);
        } else {
            ans += mx;
            cur = a[i] / abs(a[i]);
            mx = a[i];
        }
    }
    ans += mx;
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