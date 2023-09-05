#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif


void solve() {
    int n, v, m;
    cin >> n >> v >> m;
    vector dp(v + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = v; j >= a; j--)
            for (int k = m; k >= b; k--)
                dp[j][k] = max(dp[j][k], dp[j - a][k - b] + c);
    }
    cout << dp[v][m] << "\n";
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