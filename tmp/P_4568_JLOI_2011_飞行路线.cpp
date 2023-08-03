#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

template <class T = i64>
struct Dijkstra {
    int n;
    const T INF;
    using pit = std::pair<int, T>;
    using G = std::vector<std::vector<pit>>;
    G g;
    std::vector<int> parent;
    Dijkstra(int n, const T& INF = 1e18) : n(n), g(n), INF(INF), parent(n, -1) {}
    void add(int a, int b, T c) {
        g[a].emplace_back(b, c);
    }
    std::vector<T> run(int s) {
        std::vector<T> d(n, INF);
        using pti = std::pair<T, int>;
        std::priority_queue<pti, std::vector<pti>, std::greater<>> q;
        d[s] = 0;
        q.emplace(d[s], s);
        while (q.size()) {
            auto [dist, u] = q.top();
            q.pop();
            if (dist != d[u]) continue;
            for (auto& [v, w] : g[u]) {
                T fina = d[u] + w;
                if (d[v] > fina) {
                    d[v] = fina;
                    parent[v] = u;
                    q.emplace(d[v], v);
                }
            }
        }
        return d;
    }
    std::vector<int> get_path(int t) {
        std::vector<int> path;
        for (; t != -1; t = parent[t]) {
            path.push_back(t);
        }
        std::reverse(path.begin(), path.end());
        return path;
    }
    bool has_path(int t) {
        return parent[t] != -1;
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int s, t;
    cin >> s >> t;
    auto f = [&](int layer, int i) { return layer * n + i; };
    Dijkstra<i64> dij(n * (k + 1));
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        for (int layer = 0; layer < k; ++layer) {
            dij.add(f(layer, u), f(layer, v), w);
            dij.add(f(layer, v), f(layer, u), w);
            dij.add(f(layer, u), f(layer + 1, v), 0);
            dij.add(f(layer, v), f(layer + 1, u), 0);
        }
        dij.add(f(k, u), f(k, v), w);
        dij.add(f(k, v), f(k, u), w);
    }
    auto d = dij.run(f(0, s));
    i64 ans = d[f(0, t)];
    for (int layer = 1; layer <= k; ++layer) {
        ans = min(ans, d[f(layer, t)]);
    }
    cout << ans << '\n';
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