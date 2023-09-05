#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<array<int, 2>> dp(n + 1, {INF, INF});
    dp[0][1] = 0;

    for (int i = 0; i < n; i++)
        for (int who = 0; who < 2; who++)
            for (int fight = 1; fight <= min(n - i, 2); fight++) {
                int hard = a[i] + (fight > 1 ? a[i + 1] : 0);
                dp[i + fight][!who] = min(dp[i + fight][!who], dp[i][who] + who * hard);
            }

    cout << min(dp[n][0], dp[n][1]) << '\n';
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