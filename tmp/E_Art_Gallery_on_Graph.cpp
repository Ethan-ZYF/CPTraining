#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    priority_queue<pair<int, int>> q;
    vector<int> dist(n, -1);
    for (int i = 0; i < k; i++) {
        int x, h;
        cin >> x >> h;
        x--;
        q.emplace(h, x);
    }
    while (q.size()) {
        auto [d, u] = q.top();
        q.pop();
        if (dist[u] != -1) continue;
        dist[u] = d;
        if (d == 0) continue;
        for (auto v : g[u]) {
            q.emplace(d - 1, v);
        }
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (dist[i] != -1) {
            res.push_back(i + 1);
        }
    }
    cout << res.size() << '\n';
    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
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