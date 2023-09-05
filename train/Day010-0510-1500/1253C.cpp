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
    vector<i64> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    vector<i64> sum(m);
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        sum[i % m] += a[i];
        ans += sum[i % m];
        cout << ans << " \n"[i == n - 1];
    }
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