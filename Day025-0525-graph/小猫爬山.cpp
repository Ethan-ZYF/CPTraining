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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end(), greater());

    int ans = n;
    vector<int> w(n);
    auto dfs = [&](auto&& self, int u, int k) -> void {
        if (k >= ans) return;
        if (u == n) {
            ans = k;
            return;
        }
        for (int i = 0; i < k; i++) {
            if (w[i] + a[u] <= m) {
                w[i] += a[u];
                self(self, u + 1, k);
                w[i] -= a[u];
            }
        }
        w[k] = a[u];
        self(self, u + 1, k + 1);
        w[k] = 0;
    };
    dfs(dfs, 0, 0);
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