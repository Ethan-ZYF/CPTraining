#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

struct Bipartite {
    std::vector<std::vector<int>> g;
    std::vector<int> color;
    Bipartite(int n) : g(n), color(n, -1) {}

    void add(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool dfs(int u, int c) {
        color[u] = c;
        for (auto v : g[u]) {
            if (color[v] == -1) {
                if (!dfs(v, c ^ 1)) return false;
            } else if (color[v] == color[u]) {
                return false;
            }
        }
        return true;
    }

    bool work() {
        for (int i = 0; i < g.size(); i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0)) return false;
            }
        }
        return true;
    }

    std::vector<int> get_color() {
        return color;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    Bipartite g(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g.add(u, v);
    }
    if (!g.work()) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    auto color = g.get_color();
    for (int i = 0; i < n; i++)
        cout << color[i] + 1 << ' ';
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