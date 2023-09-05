#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin >> n;
    map<int, i64> f, cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        map<int, i64> g;
        for (auto [y, c] : f) {
            g[gcd(x, y)] += c;
            cnt[gcd(x, y)] += c;
        }
        g[x] += 1;
        cnt[x] += 1;
        f = g;
    }
    int ans = 0;
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << cnt[x] << '\n';
    }
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