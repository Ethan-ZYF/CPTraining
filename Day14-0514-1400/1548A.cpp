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
    vector<int> deg(n);
    vector<set<int>> wea(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        deg[u]++;
        deg[v]++;
        if (u > v) {
            wea[u].insert(v);
        } else {
            wea[v].insert(u);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ssize(wea[i]) == deg[i]) ans++;
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        debug(t);
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            int cnt1 = 0, cnt2 = 0;
            if (ssize(wea[u]) == deg[u]) cnt1++;
            if (ssize(wea[v]) == deg[v]) cnt1++;
            deg[u]++;
            deg[v]++;
            if (u > v) {
                wea[u].insert(v);
            } else {
                wea[v].insert(u);
            }
            if (ssize(wea[u]) == deg[u]) cnt2++;
            if (ssize(wea[v]) == deg[v]) cnt2++;
            ans += cnt2 - cnt1;
        } else if (t == 2) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            int cnt1 = 0, cnt2 = 0;
            if (ssize(wea[u]) == deg[u]) cnt1++;
            if (ssize(wea[v]) == deg[v]) cnt1++;
            deg[u]--;
            deg[v]--;
            if (u > v) {
                wea[u].erase(v);
            } else {
                wea[v].erase(u);
            }
            if (ssize(wea[u]) == deg[u]) cnt2++;
            if (ssize(wea[v]) == deg[v]) cnt2++;
            ans += cnt2 - cnt1;
        } else {
            cout << ans << '\n';
        }
    }
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