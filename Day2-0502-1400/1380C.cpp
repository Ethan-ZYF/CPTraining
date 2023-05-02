#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

i64 dceil(i64 a, i64 b) { return (a + b - 1) / b; }

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++) {
        int base = a[i];
        int cnt = dceil(x, base);
        if(i + cnt <= n) {
            dp[i + cnt] = max(dp[i + cnt], dp[i] + 1);
        }
    }
    cout << dp[n] << '\n';
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