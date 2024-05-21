#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    unsigned int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << k << '\n';
        return;
    }
    int x = bit_floor(k) - 1;
    cout << x << ' ' << k - x << ' ';
    for (int i = 2; i < n; i++) {
        cout << 0 << ' ';
    }
    cout << '\n';
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