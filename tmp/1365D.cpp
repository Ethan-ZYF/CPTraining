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
        if (parent[t] == -1) return {};
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
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto& s : grid) cin >> s;

    auto id = [&](int i, int j) -> int {
        return i * m + j;
    };
    Dijkstra dij(n * m);
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<int> good, bad;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') continue;
            if (grid[i][j] == 'G') good.push_back(id(i, j));
            if (grid[i][j] == 'B') bad.push_back(id(i, j));
            for (auto [dx, dy] : dir) {
                int x = i + dx;
                int y = j + dy;
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                if (grid[x][y] == '#') continue;
                dij.add(id(i, j), id(x, y), 1);
            }
        }
    }
    debug(good);
    set<int> goodpath;
    for (auto g : good) {
        auto d = dij.run(g);
        if (!dij.has_path(id(n - 1, m - 1))) {
            cout << "No\n";
            return;
        }
        auto p = dij.get_path(id(n - 1, m - 1));
        for (auto x : p) goodpath.insert(x);
    }
    debug(goodpath);
    for (auto b : bad) {
        auto d = dij.run(b);
        auto p = dij.get_path(id(n - 1, m - 1));
        for (auto x : p) {
            if (goodpath.count(x)) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
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