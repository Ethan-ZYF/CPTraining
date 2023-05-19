#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> siz(n), dep(n);
    auto dfs = [&](auto self, int u, int p) -> int {
        int res = 1;
        for (auto& v : g[u]) {
            if (v == p) continue;
            dep[v] = dep[u] + 1;
            res += self(self, v, u);
        }
        return siz[u] = res;
    };
    dfs(dfs, 0, -1);
    debug(siz);
    debug(dep);
    vector<int> diff(n);
    for (int i = 0; i < n; i++)
        diff[i] = dep[i] - siz[i] + 1;
    nth_element(diff.begin(), diff.begin() + k, diff.end(), greater<int>());
    debug(diff);
    i64 ans = accumulate(diff.begin(), diff.begin() + k, 0LL);
    cout << ans << '\n';
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