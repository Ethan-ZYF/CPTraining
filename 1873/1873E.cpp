#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    i64 n, x;
    cin >> n >> x;
    vector<i64> a(n);
    for (auto& x : a) cin >> x;
    auto check = [&](i64 m) -> bool {
        i64 sum = 0;
        for (auto& x : a) {
            sum += max(0ll, m - x);
        }
        return sum > x;
    };
    i64 l = 0, r = 1e12;
    while (l + 1 < r) {
        i64 m = (l + r) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << l << '\n';
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