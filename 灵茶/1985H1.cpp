#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
namespace rgs = std::ranges;

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
    for (auto& x : g)
        cin >> x;
    auto f = [&](int i, int j) -> int {
        return i * m + j;
    };

    DSU dsu(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') continue;
            if (i > 0 && g[i - 1][j] == '#') {
                dsu.merge(f(i, j), f(i - 1, j));
            }
            if (j > 0 && g[i][j - 1] == '#') {
                dsu.merge(f(i, j), f(i, j - 1));
            }
        }
    }

    int ans = 0;
    vector<int> ld(n * m, -1);
    for (int r = 0; r < n; r++) {
        int cur = 0, cnt = m;
        for (int j = 0; j < m; j++) {
            for (int x = max(0, r - 1); x <= min(n - 1, r + 1); x++) {
                if (g[x][j] == '#') {
                    int l = dsu.find(f(x, j));
                    if (ld[l] != r) {
                        ld[l] = r;
                        cur += dsu.size(l);
                    }
                }
            }
            if (g[r][j] == '#') cnt--;
        }
        debug(r, cur, cnt);
        ans = max(ans, cur + cnt);
    }
    ld.assign(n * m, -1);
    for (int c = 0; c < m; c++) {
        int cur = 0, cnt = n;
        for (int i = 0; i < n; i++) {
            for (int y = max(0, c - 1); y <= min(m - 1, c + 1); y++) {
                if (g[i][y] == '#') {
                    int l = dsu.find(f(i, y));
                    if (ld[l] != c) {
                        ld[l] = c;
                        cur += dsu.size(l);
                    }
                }
            }
            if (g[i][c] == '#') cnt--;
        }
        debug(c, cur, cnt);
        ans = max(ans, cur + cnt);
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