#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

struct DSU {
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n) : f(n), siz(n, 1) {
        std::iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> p(n - 1);
    for (auto& x : p) {
        cin >> x;
        x--;
    }
    p.insert(p.begin(), -1);
    debug(p);
    DSU dsu(n);
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            x = dsu.find(x);
            while (x > y) {
                dsu.merge(p[x], x);
                x = dsu.find(x);
            }
        } else {
            int x;
            cin >> x;
            x--;
            cout << dsu.find(x) + 1 << '\n';
        }
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