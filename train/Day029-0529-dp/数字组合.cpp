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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> dp(m + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= a[i]; j--) {
            dp[j] += dp[j - a[i]];
        }
    }
    cout << dp[m] << endl;
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