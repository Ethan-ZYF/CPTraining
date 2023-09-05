#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr i64 INF = 1e18;
template <class T = i64>
struct Dijkstra {
    int n;
    const T INF;
    using pit = std::pair<int, T>;
    using G = std::vector<std::vector<pit>>;
    G g;
    Dijkstra(int n, const T& INF) : n(n), g(n), INF(INF) {}
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
                    q.emplace(d[v], v);
                }
            }
        }
        return d;
    }
};


void solve() {
    int n, m;
    cin >> n >> m;
    Dijkstra dij(n, INF);
    for (int i = 0; i < m; i++) {
        i64 u, v, w;
        cin >> u >> v >> w, u--, v--;
        dij.add(u, v, w);
    }
    auto d = dij.run(0);
    for (int i = 0; i < n; i++) {
        cout << d[i] << ' ';
    }
    cout << '\n';
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