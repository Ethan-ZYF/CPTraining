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
    vector<pair<i64, i64>> a(n);
    for (auto& [x, y] : a) cin >> x >> y;
    vector<i64> need(n);
    i64 mn = 1e13;
    for (int i = 0; i < n; i++) {
        int last = (i + n - 1) % n;
        need[i] = max(0LL, a[i].first - a[last].second);
        mn = min({mn, a[i].first, a[i].second});
    }
    i64 sum = accumulate(need.begin(), need.end(), 0LL);
    cout << sum + mn << '\n';
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