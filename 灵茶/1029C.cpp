#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto& [x, y] : a) {
        cin >> x >> y;
    }
    vector<int> mxl1(n), mnr1(n, INF), mxl2(n), mnr2(n, INF);
    mxl1[0] = a[0].first;
    mnr1[0] = a[0].second;
    mxl2[n - 1] = a[n - 1].first;
    mnr2[n - 1] = a[n - 1].second;
    for (int i = 1; i < n; i++) {
        mxl1[i] = max(mxl1[i - 1], a[i].first);
        mnr1[i] = min(mnr1[i - 1], a[i].second);
    }
    for (int i = n - 2; i >= 0; i--) {
        mxl2[i] = max(mxl2[i + 1], a[i].first);
        mnr2[i] = min(mnr2[i + 1], a[i].second);
    }
    debug(mxl1);
    debug(mnr1);
    debug(mxl2);
    debug(mnr2);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int mxl = 0, mnr = INF;
        if (i > 0) {
            mxl = mxl1[i - 1];
            mnr = mnr1[i - 1];
        }
        if (i < n - 1) {
            mxl = max(mxl, mxl2[i + 1]);
            mnr = min(mnr, mnr2[i + 1]);
        }
        ans = max(ans, mnr - mxl);
    }
    cout << ans << '\n';
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