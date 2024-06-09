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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    i64 ans = 1;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        ans += abs(b[i] - a[i]);
    }
    int x;
    cin >> x;
    int add = 1e9;
    for (int i = 0; i < n; i++) {
        int mn = min(a[i], b[i]), mx = max(a[i], b[i]);
        debug(mn, mx, x);
        if (x >= mn && x <= mx) {
            add = 0;
            break;
        }
        if (x < mn) {
            add = min(add, mn - x);
        } else {
            add = min(add, x - mx);
        }
    }
    debug(ans, add);
    cout << ans + add << '\n';
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