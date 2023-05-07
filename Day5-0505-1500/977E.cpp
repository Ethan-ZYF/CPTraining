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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    DSU d(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
        d.merge(x, y);
    }
    vector<vector<int>> comp(n);
    for (int i = 0; i < n; i++) {
        comp[d.find(i)].push_back(i);
    }
    debug(comp);
    debug(g);
    int ans = 0;
    for (auto& c : comp) {
        if (ssize(c) <= 2) continue;
        bool ok = true;
        for (auto x : c) {
            if (ssize(g[x]) != 2) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }
    cout << ans << '\n';
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