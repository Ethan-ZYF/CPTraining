#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

array<int, 5> a;
int n;

void solve() {
    debug(n);
    a.fill(0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector dp(a[0] + 1, vector(a[1] + 1, vector(a[2] + 1, vector(a[3] + 1, vector(a[4] + 1, 0LL)))));
    dp[0][0][0][0][0] = 1;
    for (int i = 0; i <= a[0]; i++) {
        for (int j = 0; j <= min(i, a[1]); j++) {
            for (int k = 0; k <= min(j, a[2]); k++) {
                for (int l = 0; l <= min(k, a[3]); l++) {
                    for (int m = 0; m <= min(l, a[4]); m++) {
                        auto& cur = dp[i][j][k][l][m];
                        // debug(cur);
                        if (i and i - 1 >= j) cur += dp[i - 1][j][k][l][m];
                        if (j and j - 1 >= k) cur += dp[i][j - 1][k][l][m];
                        if (k and k - 1 >= l) cur += dp[i][j][k - 1][l][m];
                        if (l and l - 1 >= m) cur += dp[i][j][k][l - 1][m];
                        if (m) cur += dp[i][j][k][l][m - 1];
                    }
                }
            }
        }
    }
    cout << dp[a[0]][a[1]][a[2]][a[3]][a[4]] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        if (n == 0) break;
        solve();
    }

    return 0;
}