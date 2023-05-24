#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    i64 a, b, q;
    cin >> a >> b >> q;
    if (a > b) {
        swap(a, b);
    }
    i64 c = lcm(a, b);
    auto f = [&](i64 x) -> i64 {
        i64 k = x / c;
        i64 remainder = x % c + 1;
        i64 res = k * b + min(remainder, b);
        debug(x, k, remainder, res);
        return x - res;
    };
    while (q--) {
        i64 l, r;
        cin >> l >> r;
        debug(l, r);
        auto ans = f(r) - f(l - 1);
        cout << ans << ' ';
    }
    cout << '\n';
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