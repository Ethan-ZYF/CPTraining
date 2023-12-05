#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    priority_queue<int, vector<int>, greater<>> q;
    q.push(0);
    vector<int> ans;
    vector<bool> vis(n);

    while (!q.empty()) {
        int u = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        ans.push_back(u);
        for (int v : g[u]) {
            if (!vis[v]) {
                q.push(v);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " \n"[i == n - 1];
    }
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