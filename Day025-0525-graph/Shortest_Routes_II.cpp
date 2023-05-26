#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

const i64 INF = 1e18;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector g(n, vector<i64>(n, INF));
    for (int i = 0; i < n; i++) g[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        i64 w;
        cin >> u >> v >> w;
        u--, v--;
        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w);
    }

    for (int k = 0; k < n; k++)
        for (int u = 0; u < n; u++)
            for (int v = 0; v < n; v++)
                g[u][v] = min(g[u][v], g[u][k] + g[k][v]);
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << (g[u][v] == INF ? -1 : g[u][v]) << '\n';
    }
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