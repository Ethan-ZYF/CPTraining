#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr int N = 3e4 + 4;
bitset<N> f[N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<pair<int, int>> vp(m);
    vector<int> in(n);
    for (auto& [u, v] : vp)
        cin >> u >> v, u--, v--;
    sort(vp.begin(), vp.end());
    vp.erase(unique(vp.begin(), vp.end()), vp.end());

    for (auto [u, v] : vp) {
        g[v].push_back(u);
        in[u]++;
    }
    for (int i = 0; i < n; i++) {
        f[i].reset();
        f[i][i] = 1;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (in[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            f[v] |= f[u];
            in[v]--;
            if (in[v] == 0) q.push(v);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << f[i].count() << '\n';
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