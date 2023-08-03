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

    vector<array<int, 3>> dp(n + 1, {n, n, n});
    // dp[i][0] = rest
    // dp[i][1] = gym
    // dp[i][2] = contest
    dp[0] = {0, 0, 0};
    for (int i = 0; i < n; i++) {
        int x = a[i];
        dp[i + 1][0] = min({dp[i][0], dp[i][1], dp[i][2]}) + 1;
        if (x == 2 || x == 3) dp[i + 1][1] = min(dp[i][0], dp[i][2]);
        if (x == 1 || x == 3) dp[i + 1][2] = min(dp[i][0], dp[i][1]);
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
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