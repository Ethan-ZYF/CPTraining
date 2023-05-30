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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<vector<int>> g(n);
    vector<int> in(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[y].push_back(x);
        in[x]++;
        // y is x's father
    }
    int boss = -1;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            boss = i;
            break;
        }
    }

    vector<int> choose(n), not_choose(n);
    function<void(int)> dfs = [&](int u) {
        choose[u] = a[u];
        not_choose[u] = 0;
        for (auto v : g[u]) {
            dfs(v);
            choose[u] += not_choose[v];
            not_choose[u] += max(choose[v], not_choose[v]);
        }
    };
    dfs(boss);
    cout << max(choose[boss], not_choose[boss]) << endl;
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