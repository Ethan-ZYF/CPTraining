#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int w, h, k;
    cin >> w >> h;
    vector<int> x1, x2, y1, y2;
    i64 ans = 0;
    cin >> k;
    x1.resize(k);
    for (auto& x : x1) cin >> x;
    cin >> k;
    x2.resize(k);
    for (auto& x : x2) cin >> x;
    int base = max(x1.back() - x1[0], x2.back() - x2[0]);
    ans = max(ans, 1LL * base * h);
    cin >> k;
    y1.resize(k);
    for (auto& x : y1) cin >> x;
    cin >> k;
    y2.resize(k);
    for (auto& x : y2) cin >> x;
    base = max(y1.back() - y1[0], y2.back() - y2[0]);
    ans = max(ans, 1LL * base * w);
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