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
    vector g(m, vector(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            g[i][j]--;
        }
    }
    vector<set<int>> pair(n);
    for (auto& v : g) {
        for (int i = 0; i < n - 1; i++) {
            int x = v[i], y = v[i + 1];
            pair[x].insert(y);
            pair[y].insert(x);
        }
    }
    debug(pair);
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if(pair[i].count(j)) continue;
            ans++;
        }
    }
    cout << ans << '\n';
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