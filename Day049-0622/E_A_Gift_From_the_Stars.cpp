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
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
        deg[x]++, deg[y]++;
    }
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        s.emplace(deg[i], i);
    }
    vector<int> ans;
    vector<bool> alive(n, true);
    while (!s.empty()) {
        auto [d, u] = *s.begin();
        assert(d == 1);
        int v;
        for (auto x : g[u]) {
            if (alive[x]) {
                v = x;
                break;
            }
        }
        vector<int> rm;
        rm.push_back(v);
        for (auto x : g[v]) {
            rm.push_back(x);
        }
        debug(rm);
        ans.push_back(rm.size() - 1);
        for (auto x : rm) {
            s.erase({deg[x], x});
            alive[x] = false;
            for (auto y : g[x]) {
                s.erase({deg[y], y});
                deg[y]--;
                if (deg[y] > 0)
                    s.emplace(deg[y], y);
            }
        }
        debug(s);
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans) cout << x << ' ';
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