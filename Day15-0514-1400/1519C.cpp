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
    vector<i64> a(n);
    for (auto& x : a) cin >> x;
    vector<i64> b(n);
    for (auto& x : b) cin >> x;

    vector<vector<i64>> u(n);
    for (int i = 0; i < n; i++) {
        u[a[i] - 1].push_back(b[i]);
    }
    vector<i64> ans(n + 1);
    for (auto& x : u) {
        sort(x.rbegin(), x.rend());
        int m = x.size();
        vector<i64> s(m + 1);
        for (int i = 0; i < m; i++) {
            s[i + 1] = s[i] + x[i];
        }
        //! for (int k = 1; k <= n; k++)
        for (int k = 1; k <= m; k++)
            ans[k] += s[m - m % k];
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}