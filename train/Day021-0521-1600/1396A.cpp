#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    for (auto& x : a) cin >> x;
    if (n == 1) {
        cout << 1 << ' ' << 1 << '\n';
        cout << 0 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        cout << 0 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        cout << -a[0] << '\n';
        cout << '\n';
        return;
    }
    cout << 1 << ' ' << n - 1 << '\n';
    for (int i = 0; i < n - 1; i++) {
        cout << a[i] * (n - 1) << ' ';
    }
    cout << '\n';
    cout << n << ' ' << n << '\n';
    cout << -a[n - 1] << '\n';
    cout << 1 << ' ' << n << '\n';
    for (int i = 0; i < n - 1; i++) {
        cout << -a[i] * n << ' ';
    }
    cout << 0 << '\n';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}