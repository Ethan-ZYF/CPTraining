#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector a(n, vector(n, 0));
    for (auto& x : a)
        for (int& y : x)
            cin >> y;
    vector dp(n + n - 1, vector(n, vector(n, -INF)));
    dp[0][0][0] = a[0][0];
    for (int i = 1; i < n + n - 1; i++) {
        for (int x1 = 0; x1 < n; x1++) {
            for (int x2 = 0; x2 < n; x2++) {
                int y1 = i - x1, y2 = i - x2;
                if (y1 < 0 || y1 >= n || y2 < 0 || y2 >= n)
                    continue;
                int add = a[x1][y1];
                if (x1 != x2)
                    add += a[x2][y2];
                int& res = dp[i][x1][x2];
                if (x1 > 0 && x2 > 0)  //* from (x1 - 1, y1), (x2 - 1, y2)
                    res = max(res, dp[i - 1][x1 - 1][x2 - 1] + add);
                if (x1 > 0 && y2 > 0)  //* from (x1 - 1, y1), (x2, y2 - 1)
                    res = max(res, dp[i - 1][x1 - 1][x2] + add);
                if (y1 > 0 && x2 > 0)  //* from (x1, y1 - 1), (x2 - 1, y2)
                    res = max(res, dp[i - 1][x1][x2 - 1] + add);
                if (y1 > 0 && y2 > 0)  //* from (x1, y1 - 1), (x2, y2 - 1)
                    res = max(res, dp[i - 1][x1][x2] + add);
            }
        }
    }
    cout << dp.back().back().back() << '\n';
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