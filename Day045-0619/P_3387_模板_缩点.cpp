#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

struct SCC {
    int n, cur, cnt;
    std::vector<int> stk, dfn, low, bel;
    std::vector<std::vector<int>> adj;

    SCC() {}
    SCC(int n) : n(n), cur(0), cnt(0), adj(n), dfn(n, -1), low(n), bel(n, -1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(int x) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);

        for (auto y : adj[x]) {
            if (dfn[y] == -1) {
                dfs(y);
                low[x] = std::min(low[x], low[y]);
            } else if (bel[y] == -1) {
                low[x] = std::min(low[x], dfn[y]);
            }
        }

        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                bel[y] = cnt;
                stk.pop_back();
            } while (y != x);
            cnt++;
        }
    }

    std::vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i);
            }
        }
        return bel;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SCC scc(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        scc.addEdge(u, v);
    }
    auto bel = scc.work();
    debug(bel);
    vector<int> sum(scc.cnt);
    for (int i = 0; i < n; i++) {
        sum[bel[i]] += a[i];
    }

    // build new graph
    int sz = scc.cnt;
    vector<vector<int>> new_adj(sz);
    vector<int> in(sz);
    for (int u = 0; u < n; u++) {
        for (auto v : adj[u]) {
            if (bel[u] != bel[v]) {
                new_adj[bel[u]].push_back(bel[v]);
                in[bel[v]]++;
            }
        }
    }

    vector<int> dp(sz);
    queue<int> q;
    for (int i = 0; i < sz; i++) {
        if (in[i] == 0) {
            q.push(i);
            dp[i] = sum[i];
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : new_adj[u]) {
            dp[v] = max(dp[v], dp[u] + sum[v]);
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
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