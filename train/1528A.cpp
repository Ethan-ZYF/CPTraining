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
    vector<array<int, 2>> a(n);
    for (auto& [x, y] : a) cin >> x >> y;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<array<i64, 2>> dp(n, {0, 0});
    auto dfs = [&](auto dfs, int u, int p) -> void {
        for (auto v : g[u]) {
            if (v == p) continue;
            dfs(dfs, v, u);
            dp[u][0] += max(abs(a[u][0] - a[v][0]) + dp[v][0], abs(a[u][0] - a[v][1]) + dp[v][1]);
            dp[u][1] += max(abs(a[u][1] - a[v][0]) + dp[v][0], abs(a[u][1] - a[v][1]) + dp[v][1]);
        }
    };
    dfs(dfs, 0, -1);
    cout << max(dp[0][0], dp[0][1]) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}