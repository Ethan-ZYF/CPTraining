#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

struct edge {
    i64 i, to, w;
    edge(int i, int to, int w) : i(i), to(to), w(w) {}
};

void solve() {
    int n, p, k;
    cin >> n >> p >> k;
    vector<vector<vector<edge>>> g(k + 1, vector<vector<edge>>(n));
    for (int i = 0; i < p; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[0][u].emplace_back(0, v, w);
        g[0][v].emplace_back(0, u, w);
        for (int i = 1; i <= k; i++) {
            g[i][u].emplace_back(i, v, w);
            g[i][v].emplace_back(i, u, w);
            g[i - 1][u].emplace_back(i, v, 0);
            g[i - 1][v].emplace_back(i, u, 0);
        }
    }
    for (int i = 0; i < k; i++) {
        g[i][n - 1].emplace_back(i + 1, n - 1, 0);
    }
    vector<vector<i64>> dis(k + 1, vector<i64>(n, 1e18));
    dis[0][0] = 0;
    priority_queue<tuple<i64, int, int>, vector<tuple<i64, int, int>>, greater<>> pq;
    pq.emplace(0, 0, 0);
    while (!pq.empty()) {
        auto [d, i, u] = pq.top();
        pq.pop();
        if (d > dis[i][u]) continue;
        for (auto& e : g[i][u]) {
            i64 z = max(e.w, d);
            if (dis[e.i][e.to] > z) {
                dis[e.i][e.to] = z;
                pq.emplace(dis[e.i][e.to], e.i, e.to);
            }
        }
    }
    for (int i = 0; i <= k; i++) {
        debug(i, dis[i]);
    }
    i64 ans = -1;
    if (dis[k][n - 1] < 1e18) {
        ans = dis[k][n - 1];
    }
    cout << ans << '\n';
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