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
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    g[0].push_back(-1);

    auto dfs = [&](auto&& self, int u, int p) -> int {
        if (g[u].size() <= 2) return g[u].size();
        int sum = 1e9;
        for (int v : g[u]) {
            if (v == p) continue;
            sum = min(sum, self(self, v, u) + 2);
        }
        return sum;
    };
    int ans = dfs(dfs, 0, -1);
    cout << n - ans << '\n';
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