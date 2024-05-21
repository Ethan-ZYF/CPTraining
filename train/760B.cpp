#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    i64 n, m, k;
    cin >> n >> m >> k;
    i64 lo = 0, hi = m + 1;
    while (lo + 1 < hi) {
        i64 x = (lo + hi) / 2;
        i64 left = k * (x + x - k + 1) / 2;
        if (x < k) left = x * (x + 1) / 2 + (k - x);
        i64 right = (n - k) * ((x - 1) + (x - 1) - (n - k) + 1) / 2;
        if (x - 1 < n - k) right = x * (x - 1) / 2 + (n - k - (x - 1));
        debug(x, left, right);
        if (left + right <= m) {
            lo = x;
        } else {
            hi = x;
        }
    }
    cout << lo << '\n';
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