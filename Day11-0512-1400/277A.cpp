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
    vector<vector<int>> peop(n), lang(m);
    DSU dsu(n + m);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        peop[i].resize(k);
        for (auto& x : peop[i]) {
            cin >> x;
            x--;
            lang[x].push_back(i);
            dsu.merge(i, n + x);
        }
    }
    if (all_of(peop.begin(), peop.end(), [](auto& x) { return x.empty(); })) {
        cout << n << '\n';
        return;
    }
    debug(peop);
    debug(lang);
    set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(dsu.find(i));
    }
    cout << s.size() - 1 << '\n';
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