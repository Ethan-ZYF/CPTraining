#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> t(n, -1);
    t[b] = 0;
    int cycle = -1;
    auto dfs = [&](auto self, int u, int p) -> void {
        for (int v : g[u]) {
            if (v == p) continue;
            if (t[v] == -1) {
                t[v] = t[u] + 1;
                self(self, v, u);
            } else {
                if (cycle != -1) continue;
                cycle = v;
            }
        }
    };
    dfs(dfs, b, -1);
    auto bfs = [&](auto &adj_, int s) {
        std::vector<int> vis(n, -1);
        vis[s] = 0;
        std::queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (auto y : adj_[x]) {
                if (vis[y] == -1) {
                    vis[y] = vis[x] + 1;
                    q.push(y);
                }
            }
        }
        return vis;
    };
    vector<int> v = bfs(g, a);
    debug(t);
    debug(v);
    debug(a, b);
    debug(cycle);
    debug(t[cycle]);
    debug(v[cycle]);
    cout << (t[cycle] < v[cycle] ? "YES" : "NO") << "\n";
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