#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m;
    cin >> n >> m;

    vector<i64> a(n);
    debug(a);
    for (auto& y : a) cin >> y;
    if (n > m) {
        cout << 0 << endl;
        return;
    }
    i64 ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int x = abs(a[i] - a[j]);
            ans *= x;
            ans %= m;
        }
    }
    cout << ans << endl;
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