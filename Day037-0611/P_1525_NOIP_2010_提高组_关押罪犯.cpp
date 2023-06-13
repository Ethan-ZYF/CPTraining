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
    vector<array<int, 3>> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        a[i][0]--, a[i][1]--;
    }
    sort(a.begin(), a.end(), [](auto& x, auto& y) { return x[2] > y[2]; });
    DSU dsu(n * 2);
    for (auto [x, y, w] : a) {
        if(dsu.same(x, y)) {
            cout << w << '\n';
            return;
        }
        dsu.merge(x, y + n);
        dsu.merge(x + n, y);
    }
    cout << 0 << '\n';
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