#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    i64 m = 1;
    for (int i = 0; i < n; i++) {
        m = lcm(m, a[i]);
        m = gcd(m, k);
    }
    cout << (m == k ? "Yes" : "No") << '\n';
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