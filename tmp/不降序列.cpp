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
    vector<i64> a(n);
    for (i64& i : a) cin >> i;
    vector dp(n, vector(k + 1, 0LL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int op = 0; op <= k; op++) {
                if (j + op > k) break;
                int right = i + op + 1;
                if (right >= n) break;
                dp[right][j + op] = max(dp[right][j + op], dp[i][j] + 1LL * (a[right] - a[i]) * (a[right] - a[i]));
            }
        }
    }
    cout << dp[n - 1][k] << '\n';
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