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
    vector<i64> a(n);
    for (auto& x : a) cin >> x;
    vector<i64> diff(n + 1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        diff[l]++;
        diff[r]--;
    }
    partial_sum(diff.begin(), diff.end(), diff.begin());
    debug(diff);
    diff.pop_back();
    sort(diff.begin(), diff.end());
    sort(a.begin(), a.end());
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] * diff[i];
    }
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