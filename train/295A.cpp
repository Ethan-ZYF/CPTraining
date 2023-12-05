#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<i64> a(n);
    for (auto& x : a) cin >> x;
    vector<array<i64, 3>> ops(m);
    for (auto& [l, r, d] : ops) {
        cin >> l >> r >> d;
        l--;
        r--;
    }
    vector<i64> cnt(m + 1);
    while (k--) {
        int l, r;
        cin >> l >> r;
        cnt[l - 1]++, cnt[r]--;
    }

    partial_sum(cnt.begin(), cnt.end(), cnt.begin());
    vector<i64> ps(n + 1);
    for (int i = 0; i < m; i++) {
        ps[ops[i][0]] += cnt[i] * ops[i][2];
        ps[ops[i][1] + 1] -= cnt[i] * ops[i][2];
    }
    partial_sum(ps.begin(), ps.end(), ps.begin());
    for (int i = 0; i < n; i++) {
        cout << a[i] + ps[i] << " \n"[i == n - 1];
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