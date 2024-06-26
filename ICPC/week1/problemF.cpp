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

    DSU(int n) : p(n + 1), siz(n + 1, 1) {
        std::iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        siz[x] += siz[y];
        p[y] = x;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    DSU dsu(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        dsu.merge(u, v);
        deg[v]++;
    }

    // topo sort
    vector<bool> in_cycle(n, true);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    i64 ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_cycle[u] = false;
        for (auto v : g[u]) {
            if (--deg[v] == 0) {
                ans++;
                q.push(v);
            }
        }
    }
    map<int, int> clen;
    for (int i = 0; i < n; i++) {
        if (in_cycle[dsu.find(i)]) {
            clen[dsu.find(i)]++;
        }
    }
    debug(m, ans);
    debug(in_cycle);
    debug(clen);
    for (auto [k, v] : clen) {
        if (v == 1)
            continue;
        ans += v + 1;
    }
    cout << ans << '\n';
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