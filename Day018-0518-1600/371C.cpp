#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    string S;
    cin >> S;
    i64 nb, ns, nc, pb, ps, pc;
    cin >> nb >> ns >> nc >> pb >> ps >> pc;
    i64 b = 0, s = 0, c = 0;
    for (auto& x : S) {
        if (x == 'B') b++;
        if (x == 'S') s++;
        if (x == 'C') c++;
    }
    debug(b, s, c);
    i64 r;
    cin >> r;
    auto check = [&](i64 x) -> bool {
        i64 cost = 0;
        cost += max(0LL, x * b - nb) * pb;
        cost += max(0LL, x * s - ns) * ps;
        cost += max(0LL, x * c - nc) * pc;
        return cost <= r;
    };
    i64 lo = 0, hi = 1e13;
    while (lo + 1 < hi) {
        i64 mid = (lo + hi) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << lo << endl;
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