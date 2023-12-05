#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> pos(n), ans1(n);
    for (int i = 0; i < n; i++) {
        cin >> ans1[i];
        ans1[i]--;
        pos[ans1[i]] = i;
    }
    auto f = [&](int u, int v) { return pos[u] < pos[v]; };
    for (int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end(), f);
    }
    vector<int> ans;
    queue<int> q;
    vector<bool> vis(n);
    q.push(0);
    vis[0] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (ans[i] != ans1[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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