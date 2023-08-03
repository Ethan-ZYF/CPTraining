#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

struct DSU {
    std::vector<int> p, siz;
    DSU(int n) : p(n + 1), siz(n + 1, 1) { std::iota(p.begin(), p.end(), 0); }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        siz[x] += siz[y];
        p[y] = x;
        return true;
    }
    int size(int x) { return siz[find(x)]; }
};

constexpr i64 INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    bool ok = true;
    vector<map<int, i64>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        if (g[u].count(v) and g[u][v] != w) {
            ok = false;
        }
        g[u][v] = w;
        if (g[v].count(u) and g[v][u] != -w) {
            ok = false;
        }
        g[v][u] = -w;
        dsu.merge(u, v);
    }
    if (!ok) {
        cout << "NO" << endl;
        return;
    }
    debug("OK");
    vector<bool> vis(n);
    for (int p = 0; p < n; p++) {
        if (vis[p]) continue;
        // vector<i64> dist(n, INF);
        map<int, i64> dist;
        dist[p] = 0;
        auto dfs = [&](auto self, int u) -> bool {
            vis[u] = true;
            for (auto [v, w] : g[u]) {
                if (dist.find(v) != dist.end()) {
                    if (dist[v] != dist[u] + w) {
                        return false;
                    }
                } else {
                    dist[v] = dist[u] + w;
                    if (!self(self, v)) return false;
                }
            }
            return true;
        };
        if (!dfs(dfs, p)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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