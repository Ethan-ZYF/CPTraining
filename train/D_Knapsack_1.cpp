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
    vector<i64> dp(m + 1);

    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        for (int j = m; j >= w; j--)
            dp[j] = max(dp[j], dp[j - w] + v);
    }

    cout << dp[m] << endl;
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