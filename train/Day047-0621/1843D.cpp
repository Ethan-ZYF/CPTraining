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
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> a(n);
    for (int i = 1; i < n; i++) {
        a[i] = g[i].size() == 1;
    }
    auto dfs = [&](auto&& self, int u, int p) -> int {
        for (auto v : g[u]) {
            if (v == p) continue;
            a[u] += self(self, v, u);
        }
        return a[u];
    };
    dfs(dfs, 0, -1);
    debug(a);

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << 1LL * a[u] * a[v] << '\n';
    }
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