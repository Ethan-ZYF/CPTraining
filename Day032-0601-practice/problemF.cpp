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
    vector<int> a(n);
    vector<vector<int>> g(n);
    for (auto& x : a) cin >> x;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (m % 2 == 0) {
        cout << 0 << '\n';
        return;
    }
    int ans = accumulate(a.begin(), a.end(), 0);
    for (int i = 0; i < n; i++) {
        if (g[i].size() % 2 == 1) {
            ans = min(ans, a[i]);
            continue;
        }
        for (int j : g[i]) {
            if (g[j].size() % 2 == 0) {
                ans = min(ans, a[i] + a[j]);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}