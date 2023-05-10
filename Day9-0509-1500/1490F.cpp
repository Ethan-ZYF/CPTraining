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
    map<int, int> cnt;
    for (auto x : a) cnt[x]++;
    vector<i64> b;
    for (auto [x, c] : cnt) {
        b.push_back(c);
    }
    sort(b.begin(), b.end());
    int sz = ssize(b);
    vector<i64> c(sz + 1);
    partial_sum(b.begin(), b.end(), c.begin() + 1);
    int ans = n;
    for (int i = 0; i < sz; i++) {
        int left = c[i];
        int right = c[sz] - c[i] - b[i] * (sz - i);
        ans = min(ans, left + right);
    }
    cout << ans << '\n';
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