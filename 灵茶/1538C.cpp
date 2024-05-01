#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    sort(a.begin(), a.end());

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int x = l - a[i];
        int y = r - a[i];
        auto p = lower_bound(a.begin(), a.begin() + i, x);
        auto q = upper_bound(a.begin(), a.begin() + i, y);
        ans += q - p;
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