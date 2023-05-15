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
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> a(k);
        for (int j = 0; j < k; j++) {
            cin >> a[j];
            a[j]--;
        }
        for (int j = 1; j < k; j++) {
            dsu.merge(a[0], a[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dsu.size(i) << " \n"[i == n - 1];
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