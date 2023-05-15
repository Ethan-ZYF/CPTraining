#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif


void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(n * m);
    for (int i = 0; i < n * m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int mid = a[n * m / 2];
    int ans = 0;
    for (auto& x : a) {
        if (abs(x - mid) % d != 0) {
            cout << -1 << '\n';
            return;
        }
        ans += abs(x - mid) / d;
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