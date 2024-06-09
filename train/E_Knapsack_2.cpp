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
    vector<i64> dp = {0};
    i64 s = 0;
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        s += v;
        dp.resize(s + 1, 1e18);
        for (int j = s; j >= v; j--)
            dp[j] = min(dp[j], dp[j - v] + w);
    }
    int ans = 0;
    for (int i = 0; i <= s; i++)
        if (dp[i] <= m) ans = i;
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