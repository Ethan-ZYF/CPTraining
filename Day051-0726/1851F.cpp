#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    int t = (1 << k) - 1;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    auto xnor = [&](int x, int y) {
        int ans = x & y | (~x & ~y);
        return ans & t;
    };
    sort(a.begin(), a.end());
    int ans = -1;
    int r0 = -1, r1 = -1, x = -1;
    for (int i = 0; i < n - 1; i++) {
        auto [x1, i1] = a[i];
        auto [x2, i2] = a[i + 1];
        int cur = xnor(x1, x2);
        if (cur > ans) {
            ans = cur;
            r0 = i1;
            r1 = i2;
            x = t - (x1 & x2);
        }
    }
    cout << r0 + 1 << " " << r1 + 1 << " " << x << "\n";
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