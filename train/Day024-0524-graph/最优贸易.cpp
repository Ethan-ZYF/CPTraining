#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

/*
 * @autor: Andrew1729
 */
template <class T = int>
struct Dijkstra {
    int n;
    const T INF;
    typedef std::pair<int, T> pit;
    typedef std::vector<std::vector<pit>> G;
    G g;
    Dijkstra(int n, const T& INF) : n(n), g(n), INF(INF) {}
    Dijkstra(const G& g, const T& INF) : g(g), INF(INF) {}
    void add(int a, int b, T c) {
        g[a].emplace_back(b, c);
    }
    T run(int s, int t) {
        std::vector<T> d(n, INF);
        typedef std::pair<T, int> pti;
        std::priority_queue<pti, std::vector<pti>, std::greater<pti>> q;
        d[s] = 0;
        q.emplace(d[s], s);
        while (q.size()) {
            auto [dist, u] = q.top();
            q.pop();
            if (dist != d[u]) continue;
            for (auto& [v, w] : g[u]) {
                int fina = d[u] + w;
                if (d[v] > fina) {
                    d[v] = fina;
                    q.emplace(d[v], v);
                }
            }
        }
        return d[t] == INF ? -1 : d[t];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
        x *= -1;
    }
    auto f = [&](int layer, int i) -> int {
        return layer * n + i;
    };
    Dijkstra<int> dij(n * 3, 1e9);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w, u--, v--;
        dij.add(f(0, u), f(0, v), 0);
        dij.add(f(1, u), f(1, v), 0);
        dij.add(f(2, u), f(2, v), 0);

        // buy
        dij.add(f(0, u), f(1, v), -a[u]);
        // sell
        dij.add(f(1, u), f(2, v), a[u]);
        if (w == 2) {
            dij.add(f(0, v), f(0, u), 0);
            dij.add(f(1, v), f(1, u), 0);
            dij.add(f(2, v), f(2, u), 0);

            // buy
            dij.add(f(0, v), f(1, u), -a[v]);
            // sell
            dij.add(f(1, v), f(2, u), a[v]);
        }
    }
    for (int u = 0; u < n; u++) {
        dij.add(f(0, u), f(2, u), 0);
        dij.add(f(1, u), f(2, u), a[u]);
    }
    int res = dij.run(f(0, 0), f(2, n - 1));
    cout << -res << '\n';
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