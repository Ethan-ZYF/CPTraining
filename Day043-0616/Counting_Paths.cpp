#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

struct LCA {
    int n, rt, lg;
    std::vector<std::vector<int>> g;
    std::vector<std::vector<int>> anc;
    std::vector<int> dep;

    LCA(int n) : n(n), rt(0), lg(std::__lg(n) + 1), g(n), anc(n, std::vector<int>(lg, -1)), dep(n) {}

    void add(int x, int y) {
        g[x].push_back(y);
        g[y].push_back(x);
    }

    void dfs(int u, int fa) {
        anc[u][0] = fa;
        dep[u] = dep[fa] + 1;
        for (auto v : g[u]) {
            if (v != fa) {
                dep[v] = dep[u] + 1;
                dfs(v, u);
            }
        }
    }

    void build(int rt) {
        this->rt = rt;
        dfs(rt, -1);
        for (int i = 1; i < lg; i++) {
            for (int j = 0; j < n; j++) {
                if (anc[j][i - 1] != -1) {
                    anc[j][i] = anc[anc[j][i - 1]][i - 1];
                }
            }
        }
    }
    int kth(int x, int k) {
        for (; k; k &= k - 1)
            x = anc[x][__builtin_ctz(k)];
        return x;
    }

    int lca(int x, int y) {
        if (dep[x] > dep[y])
            std::swap(x, y);
        y = kth(y, dep[y] - dep[x]);
        if (y == x)
            return x;
        for (int i = anc[x].size() - 1; i >= 0; i--) {
            int px = anc[x][i], py = anc[y][i];
            if (px != py) {
                x = px;
                y = py;
            }
        }
        return anc[x][0];
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    LCA lca(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
        lca.add(x, y);
    }
    vector<int> a(n);

    lca.build(0);
    debug(lca.kth(0, 1));

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int o = lca.lca(x, y);
        int p = lca.kth(o, 1);
        debug(x, y, o, p);
        a[x]++;
        a[y]++;
        a[o]--;
        if (p != -1) {
            a[p]--;
        }
    }
    auto dfs = [&](auto &self, int u, int fa) -> void {
        for (auto v : g[u]) {
            if (v != fa) {
                self(self, v, u);
                a[u] += a[v];
            }
        }
    };
    dfs(dfs, 0, -1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
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