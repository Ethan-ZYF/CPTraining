#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m, r;
    cin >> n >> m >> r;

    vector<array<int, 3>> shot(r);
    vector<int> tm;
    for (int i = 0; i < r; i++) {
        int t, d, p;
        cin >> t >> d >> p;
        shot[i] = {t, d, p};
        tm.push_back(t);
    }
    sort(tm.begin(), tm.end());

    tm.erase(unique(tm.begin(), tm.end()), tm.end());
    r = tm.size();

    vector sh(n + 1, vector(m + 1, vector(r + 1, false)));
    for (auto [t, d, p] : shot) {
        t = lower_bound(tm.begin(), tm.end(), t) - tm.begin();
        if (d == 1) {
            for (int j = 0; j <= m; j++) {
                sh[p][j][t] = true;
            }
        } else {
            for (int i = 0; i <= n; i++) {
                sh[i][p][t] = true;
            }
        }
    }

    vector dp(n + 1, vector(m + 1, vector(r + 1, -1)));
    dp[0][0][0] = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i > 0) {
                for (int k = 0; k <= r; k++) {
                    if (dp[i - 1][j][k] != -1) {
                        if (dp[i][j][k] == -1 || dp[i][j][k] > dp[i - 1][j][k] + 1) {
                            dp[i][j][k] = dp[i - 1][j][k] + 1;
                        }
                        if (k < r && !sh[i][j][k]) {
                            dp[i][j][k + 1] = tm[k];
                        }
                    }
                }
            }
            if (j > 0) {
                for (int k = 0; k <= r; k++) {
                    if (dp[i][j - 1][k] != -1) {
                        if (dp[i][j][k] == -1 || dp[i][j][k] > dp[i][j - 1][k] + 1) {
                            dp[i][j][k] = dp[i][j - 1][k] + 1;
                        }
                        if (k < r && !sh[i][j][k]) {
                            dp[i][j][k + 1] = tm[k];
                        }
                    }
                }
            }
            for (int k = 0; k < r; k++) {
                if (dp[i][j][k] >= tm[k]) {
                    dp[i][j][k] = -1;
                }
            }
            for (int k = 0; k < r; k++) {
                if (dp[i][j][k] != -1 && !sh[i][j][k]) {
                    dp[i][j][k + 1] = tm[k];
                }
            }
        }
    }

    int ans = -1;
    for (int k = 0; k <= r; k++) {
        if (dp[n][m][k] != -1) {
            ans = dp[n][m][k];
            break;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}