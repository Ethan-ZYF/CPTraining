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
    int mx = 0, mxi = -1;
    for (int i = 0; i < n; i++) {
        int& x = a[i];
        if (x >= 0) {
            x = -x - 1;
        }
        if (abs(x) > mx) {
            mx = abs(x);
            mxi = i;
        }
    }
    if (n & 1) {
        a[mxi] = -a[mxi] - 1;
    }
    for (auto x : a) cout << x << ' ';
    cout << '\n';
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