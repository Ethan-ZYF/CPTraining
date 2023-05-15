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
    vector<string> grid(n);
    for (auto& s : grid) cin >> s;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = grid[i][j] == '#' ? 1 : 0;
        }
    }
    for (int i = 1; i < n; i++) {
        if (grid[i][0] == '#' and grid[i - 1][0] == '.') {
            dp[i][0] = dp[i - 1][0] + 1;
        } else {
            dp[i][0] = dp[i - 1][0];
        }
    }
    for (int j = 1; j < m; j++) {
        if (grid[0][j] == '#' and grid[0][j - 1] == '.') {
            dp[0][j] = dp[0][j - 1] + 1;
        } else {
            dp[0][j] = dp[0][j - 1];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i][j] == '#') {
                int a = 1e9, b = 1e9;
                if (grid[i - 1][j] == '.') {
                    a = dp[i - 1][j] + 1;
                } else {
                    a = dp[i - 1][j];
                }
                if (grid[i][j - 1] == '.') {
                    b = dp[i][j - 1] + 1;
                } else {
                    b = dp[i][j - 1];
                }
                dp[i][j] = min(a, b);
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp.back().back() << endl;
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