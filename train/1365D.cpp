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
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
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
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto& row : g) cin >> row;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'G') cnt++;
            if (g[i][j] != 'B') continue;
            debug(i, j, g[i][j]);
            if (i and g[i - 1][j] == '.') g[i - 1][j] = '#';
            if (j and g[i][j - 1] == '.') g[i][j - 1] = '#';
            if (i + 1 < n and g[i + 1][j] == '.') g[i + 1][j] = '#';
            if (j + 1 < m and g[i][j + 1] == '.') g[i][j + 1] = '#';
        }
    }
    auto f = [&](int i, int j) -> int {
        return i * m + j;
    };

    DSU d(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '#') continue;
            int x1 = f(i, j);
            if (i + 1 < n and g[i + 1][j] != '#') d.merge(x1, f(i + 1, j));
            if (j + 1 < m and g[i][j + 1] != '#') d.merge(x1, f(i, j + 1));
        }
    }
    if (g[n - 1][m - 1] == '#') {
        if (cnt)
            cout << "No\n";
        else
            cout << "Yes\n";
        return;
    }
    int l = d.find(f(n - 1, m - 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'G') {
                if (!d.same(f(i, j), l)) {
                    cout << "No\n";
                    return;
                }
            } else if (g[i][j] == 'B') {
                if (d.same(f(i, j), l)) {
                    cout << "No\n";
                    return;
                }
            }
        }
    }
    cout << "Yes\n";
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