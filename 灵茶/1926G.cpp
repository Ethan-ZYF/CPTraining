#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr int inf = 1e9 + 9;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int u;
        cin >> u;
        u--;
        g[u].push_back(i);
    }

    string s;
    cin >> s;

    vector<array<int, 3>> dp(n, {inf, inf, inf});
    auto dfs = [&](auto&& self, int u) -> void {
        dp[u][s[u] == 'P' ? 1 : (s[u] == 'S' ? 2 : 0)] = 0;
        for (int v : g[u]) {
            self(self, v);
            array<int, 3> ndp = {inf, inf, inf};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i | j != 3)
                        ndp[i | j] = min(ndp[i | j], dp[u][i] + dp[v][j]);
                    ndp[i] = min(ndp[i], dp[u][i] + dp[v][j] + 1);
                }
            }
            dp[u] = ndp;
        }
    };
    dfs(dfs, 0);
    cout << min({dp[0][0], dp[0][1], dp[0][2]}) << '\n';
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