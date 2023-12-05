#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> in(n), out(n);
    int ts = 0;
    function<void(int, int)> dfs = [&](int u, int p) {
        in[u] = ts++;
        for (int v : g[u]) {
            if (v != p) {
                dfs(v, u);
            }
        }
        out[u] = ts;
    };
    dfs(0, -1);
    vector<i64> pref(ts + 1);
    for (int i = 0; i < q; i++) {
        int u, x;
        cin >> u >> x;
        u--;
        pref[in[u]] += x;
        pref[out[u]] -= x;
    }
    partial_sum(pref.begin(), pref.end(), pref.begin());
    for (int i = 0; i < n; i++) {
        cout << pref[in[i]] << " \n"[i == n - 1];
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