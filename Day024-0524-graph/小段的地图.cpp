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
    const T INF = 1e9;
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
    int n, m, k;
    cin >> n >> m >> k;
    Dijkstra dij(n * 2, 1e9);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        if(u == v) continue;
        if (c == 1) {
            dij.add(u, v, 1);
            dij.add(v, u, 1);
        }else{
            dij.add(u + n, v + n, 1);
            dij.add(v + n, u + n, 1);
        }

    }
    for (int i = 0; i < k; i++) {
        int x, w;
        cin >> x >> w;
        x--;
        dij.add(x, x + n, w);
        dij.add(x + n, x, w);
    }
    int s, t;
    cin >> s >> t;
    s--, t--;
    int r1 = dij.run(s, t);
    int r2 = dij.run(s, t + n);
    if (r1 == -1 && r2 == -1) {
        cout << -1 << "\n";
        return;
    }
    if (r1 == -1) {
        cout << r2 << "\n";
        return;
    }
    if (r2 == -1) {
        cout << r1 << "\n";
        return;
    }
    cout << min(r1, r2) << "\n";
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