#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, x;
    cin >> n >> x;
    x--;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> siz(n), isleaf(n);
    auto dfs = [&](auto self, int u, int p) -> int {
        int res = 1;
        if (g[u].size() == 1) {
            isleaf[u] = true;
        }
        for (auto& v : g[u]) {
            if (v == p) continue;
            res += self(self, v, u);
        }
        return siz[u] = res;
    };
    dfs(dfs, x, -1);
    debug(siz);
    debug(isleaf);
    if (isleaf[x] or n == 1) {
        cout << "Ayush\n";
        return;
    }
    if (siz[x] % 2 == 0) {
        cout << "Ayush\n";
    } else {
        cout << "Ashish\n";
    }
};

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