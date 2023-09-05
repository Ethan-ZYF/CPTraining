#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif


void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> a(n);
    for (auto& [t, l, h] : a) cin >> t >> l >> h;
    debug(a);
    int lo = m, hi = m;
    int time = 0;
    for (auto& [t, l, h] : a) {
        int dt = t - time;
        lo -= dt;
        hi += dt;
        if (lo > h || hi < l) {
            cout << "NO\n";
            return;
        }
        lo = max(lo, l);
        hi = min(hi, h);
        time = t;
    }
    cout << "YES\n";
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