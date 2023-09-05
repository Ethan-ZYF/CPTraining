#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    i64 n, g, b;
    cin >> n >> g >> b;
    i64 half = (n + 1) / 2;
    i64 need = (half + g - 1) / g;
    i64 ans = (need - 1) * b + half;
    cout << max(ans, n) << '\n';
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