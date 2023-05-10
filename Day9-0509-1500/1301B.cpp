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
    for (auto& x : a) cin >> x;
    int mx = numeric_limits<int>::min();
    int mn = numeric_limits<int>::max();
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == -1 && a[i + 1] != -1) {
            mx = max(mx, a[i + 1]);
            mn = min(mn, a[i + 1]);
        } else if (a[i] != -1 && a[i + 1] == -1) {
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        } else {
            ans = max(ans, abs(a[i] - a[i + 1]));
        }
    }
    if (mx < mn) {
        cout << 0 << " " << 0 << "\n";
    } else {
        cout << max(ans, (mx - mn + 1) / 2) << " " << (mn + mx) / 2 << "\n";
    }
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