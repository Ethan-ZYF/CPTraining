#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr int N = 1e5 + 5;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> X(N);
    vector<vector<int>> Y(N);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            X[x].push_back(i);
            Y[x].push_back(j);
        }
    i64 ans = 0;
    for (auto& v : X) {
        sort(v.begin(), v.end());
        int sz = v.size();
        if (sz <= 1) continue;
        for (int i = 0; i < sz - 1; i++) {
            ans += 1LL * (v[i + 1] - v[i]) * (i + 1) * (sz - i - 1);
        }
    }
    for (auto& v : Y) {
        sort(v.begin(), v.end());
        int sz = v.size();
        if (sz <= 1) continue;
        for (int i = 0; i < sz - 1; i++) {
            ans += 1LL * (v[i + 1] - v[i]) * (i + 1) * (sz - i - 1);
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