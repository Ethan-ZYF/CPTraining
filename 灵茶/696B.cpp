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
    for (int i = 1; i < n; i++) {
        int u;
        cin >> u;
        u--;
        g[u].push_back(i);
    }

    vector<int> a(n), b(n);
    int timestamp = 0;
    auto dfs = [&](auto&& self, int u, bool reverse) -> void {
        if (reverse) {
            b[u] = ++timestamp;
            for (auto v : ranges::views::reverse(g[u]))
                self(self, v, reverse);
        } else {
            a[u] = ++timestamp;
            for (auto v : g[u])
                self(self, v, reverse);
        }
    };
    dfs(dfs, 0, false);
    timestamp = 0;
    dfs(dfs, 0, true);

    cout << fixed << setprecision(1);
    for (int i = 0; i < n; i++)
        cout << 0.5 * (a[i] + b[i]) << " \n"[i == n - 1];
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