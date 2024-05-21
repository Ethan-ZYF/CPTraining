#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    if (x + 1 == y) {
        cout << -1 << '\n';
        return;
    }
    int ans = 0;
    while (gcd(x, y) == 1) {
        x++, y++, ans++;
    }
    debug(x, y, gcd(x, y));
    cout << ans << '\n';
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