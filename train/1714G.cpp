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
    vector<vector<array<int, 3>>> g(n);
    for (int i = 1; i < n; i++) {
        int p, a, b;
        cin >> p >> a >> b;
        --p;
        g[p].push_back({i, a, b});
    }

    vector<int> ans(n, -1);
    vector<i64> A(n), B(n), s;
    auto dfs = [&](auto&& self, int u) -> void {
        s.push_back(B[u]);
        if (u) {
            ans[u] = upper_bound(s.begin(), s.end(), A[u]) - s.begin() - 1;
        }
        for (auto& [v, a, b] : g[u]) {
            A[v] = A[u] + a;
            B[v] = B[u] + b;
            self(self, v);
        }
        s.pop_back();
    };
    dfs(dfs, 0);
    for (int i = 1; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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