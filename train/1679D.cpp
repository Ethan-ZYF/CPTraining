#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    i64 n, m, k;
    cin >> n >> m >> k;
    vector a(n, 0);
    for (auto& x : a) cin >> x;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }

    auto check = [&](int x) -> bool {
        vector<int> in(n);
        int cnt1 = 0, cnt2 = 0;
        for (int u = 0; u < n; u++) {
            if (a[u] > x) continue;
            cnt1++;
            for (auto v : g[u]) {
                if (a[v] > x) continue;
                in[v]++;
            }
        }
        queue<int> q;
        vector<int> depth(n, 0);
        for (int u = 0; u < n; u++) {
            if (in[u] == 0 and a[u] <= x) {
                q.push(u);
                depth[u] = 1;
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cnt2++;
            for (auto v : g[u]) {
                if (a[v] > x) continue;
                in[v]--;
                depth[v] = max(depth[v], depth[u] + 1);
                if (in[v] == 0) {
                    q.push(v);
                }
            }
        }
        return (cnt1 > cnt2 or *max_element(depth.begin(), depth.end()) >= k);
    };

    int lo = 0, hi = 1e9 + 5;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    if (hi > 1e9) hi = -1;
    cout << hi << '\n';
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