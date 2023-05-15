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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = a[i] - i;
    }
    debug(b);
    map<int, i64> sum;
    for (int i = 0; i < n; i++) {
        sum[b[i]] += a[i];
    }
    i64 ans = ranges::max(sum | views ::values);
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