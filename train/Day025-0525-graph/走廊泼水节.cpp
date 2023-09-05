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

void solve() {
    int n;
    cin >> n;
    DSU dsu(n);
    i64 ans = 0;
    vector<array<int, 3>> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w, --u, --v;
        edges[i] = {w, u, v};
    }
    sort(edges.begin(), edges.end());
    for (auto [w, u, v] : edges) {
        ans += 1LL * (dsu.size(u) * dsu.size(v) - 1) * (w + 1);
        dsu.merge(u, v);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}