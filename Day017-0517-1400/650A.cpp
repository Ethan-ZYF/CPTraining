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
    map<int, int> X, Y;
    map<pair<int, int>, int> cnt;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        X[x]++, Y[y]++;
        cnt[{x, y}]++;
    }
    for (auto [x, cnt] : X) {
        ans += 1LL * cnt * (cnt - 1) / 2;
    }
    for (auto [y, cnt] : Y) {
        ans += 1LL * cnt * (cnt - 1) / 2;
    }
    for (auto [p, c] : cnt) {
        ans -= 1LL * c * (c - 1) / 2;
    }
    cout << ans << '\n';
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