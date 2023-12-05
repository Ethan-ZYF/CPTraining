#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int h, c, t;
    cin >> h >> c >> t;
    if (2 * t <= h + c) {
        cout << 2 << '\n';
        return;
    }
    int a = h - t;
    int b = 2 * t - c - h;
    int k = 2 * (a / b) + 1;
    long long val1 = abs(k / 2 * 1ll * c + (k + 1) / 2 * 1ll * h - t * 1ll * k);
    long long val2 = abs((k + 2) / 2 * 1ll * c + (k + 3) / 2 * 1ll * h - t * 1ll * (k + 2));
    if (val1 * (k + 2) <= val2 * k) {
        cout << k << '\n';
    } else {
        cout << k + 2 << '\n';
    }
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