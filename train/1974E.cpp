#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, x;
    cin >> n >> x;
    vector<i64> dp = {0};
    i64 s = 0;
    for (int i = 0; i < n; i++) {
        int c, h;
        cin >> c >> h;
        s += h;
        dp.resize(s + 1, -1);
        for (int j = s; j >= h; j--)
            if (dp[j - h] >= c) dp[j] = max(dp[j], dp[j - h] - c);
        for (auto& i : dp)
            if (i >= 0) i = i + x;
    }

    i64 ans = 0;
    for (int i = 0; i <= s; i++)
        if (dp[i] >= 0) ans = i;
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}