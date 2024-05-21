#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif
struct TwoSat {
    int n;
    std::vector<std::vector<int>> e;
    std::vector<bool> ans;

    TwoSat(int n) : n(n), e(2 * n), ans(n) {}

    void addClause(int u, bool f, int v, bool g) {
        e[2 * u + !f].push_back(2 * v + g);
        e[2 * v + !g].push_back(2 * u + f);
    }

    bool satisfiable() {
        std::vector<int> id(2 * n, -1), dfn(2 * n, -1), low(2 * n, -1);
        std::vector<int> stk;
        int now = 0, cnt = 0;
        std::function<void(int)> tarjan = [&](int u) {
            stk.push_back(u);
            dfn[u] = low[u] = now++;
            for (auto v : e[u]) {
                if (dfn[v] == -1) {
                    tarjan(v);
                    low[u] = std::min(low[u], low[v]);
                } else if (id[v] == -1) {
                    low[u] = std::min(low[u], dfn[v]);
                }
            }
            if (dfn[u] == low[u]) {
                int v;
                do {
                    v = stk.back();
                    stk.pop_back();
                    id[v] = cnt;
                } while (v != u);
                ++cnt;
            }
        };
        for (int i = 0; i < 2 * n; ++i)
            if (dfn[i] == -1) tarjan(i);
        for (int i = 0; i < n; ++i) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            ans[i] = id[2 * i] > id[2 * i + 1];
        }
        return true;
    }

    std::vector<bool> answer() {
        return ans;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int len;
        cin >> len;
        for (int j = 0; j < len; j++) {
            int x;
            cin >> x;
            x--;
            g[x].push_back(i);
        }
    }
    TwoSat ts(m);
    for (int i = 0; i < n; i++) {
        debug(a[i], g[i]);
        if (a[i]) {
            ts.addClause(g[i][0], 0, g[i][1], 1);
            ts.addClause(g[i][0], 1, g[i][1], 0);
        } else {
            ts.addClause(g[i][0], 0, g[i][1], 0);
            ts.addClause(g[i][0], 1, g[i][1], 1);
        }
    }
    cout << (ts.satisfiable() ? "YES" : "NO") << '\n';
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