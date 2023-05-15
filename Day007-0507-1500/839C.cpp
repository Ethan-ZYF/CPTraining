#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif
int Task;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto dfs = [&](auto&& self, int u, int p) -> double {
        double res = 0;
        for (auto v : adj[u]) {
            if (v == p) continue;
            res += self(self, v, u) + 1;
        }
        return res ? res / (adj[u].size() - (p != -1)) : 0;
    };
    double ans = dfs(dfs, 0, -1);
    cout << fixed << setprecision(15) << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    for (Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}