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
    vector<vector<int>> g(n);
    set<pair<int, int>> s;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        s.insert({u, v});
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dp(n);
    auto dfs1 = [&](auto&& self, int u, int p) -> void {
        for (auto v : g[u]) {
            if (v == p)
                continue;
            self(self, v, u);
            dp[u] += dp[v];
            if (s.count({u, v})) {
                dp[u]++;
            }
        }
    };

    dfs1(dfs1, 0, -1);
    debug(dp);

    vector<int> ans;
    int best = n;
    auto check = [&](int u, int x) {
        if (x < best) {
            ans.clear();
            ans.push_back(u);
            best = x;
        } else {
            ans.push_back(u);
        }
    };

    auto dfs2 = [&](auto&& self, int u, int p, int up) -> void {
        check(u, dp[u] + up);
        for (auto v : g[u]) {
            if (v == p)
                continue;
            int extra = dp[u] - dp[v] + (s.count({u, v}) ? -1 : 1);
            self(self, v, u, up + extra);
        }
    };
    dfs2(dfs2, 0, -1, 0);
    sort(ans.begin(), ans.end());
    cout << best << '\n';
    for (auto x : ans) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
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