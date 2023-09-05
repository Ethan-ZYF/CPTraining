#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

/*
 * @author jiangly
 * https://codeforces.com/profile/jiangly
 */
i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    i64 g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

void solve() {
    i64 a, b;
    cin >> a >> b;
    i64 x, y;
    i64 g = exgcd(a, b, x, y);
    debug(g, x, y);
    x %= b;
    if (x < 0) x += b;
    cout << x << '\n';
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