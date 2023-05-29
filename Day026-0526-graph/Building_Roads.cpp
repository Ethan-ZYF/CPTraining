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
    DSU d(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v, --u, --v;
        d.merge(u, v);
    }
    vector<int> f;
    for (int i = 0; i < n; i++) {
        if (d.find(i) == i) {
            f.push_back(i);
        }
    }
    cout << f.size() - 1 << '\n';
    for (int i = 1; i < f.size(); i++) {
        cout << f[i - 1] + 1 << ' ' << f[i] + 1 << '\n';
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