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

    if (!is_sorted(a.begin(), a.end())) {
        cout << 0 << '\n';
        return;
    }
    int mx = 1e9;
    for (int i = 0; i < n - 1; i++) {
        mx = min(mx, a[i + 1] - a[i]);
    }
    debug(mx);
    cout << mx / 2 + 1 << '\n';
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