#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    vector<array<int, 4>> dp(n + 1, {-1, -1, -1, 0});
    // OO OX XO XX
    for (int i = 0; i < n; i++) {
        int state = (s1[i] == 'X' ? 2 : 0) + (s2[i] == 'X' ? 1 : 0);
        dp[i + 1][state] = max({dp[i][0], dp[i][1], dp[i][2], dp[i][3]});
        switch (state) {
            case 0:
                dp[i + 1][1] = dp[i][0] + 1;
                dp[i + 1][2] = dp[i][0] + 1;
                dp[i + 1][3] = max(dp[i][1], dp[i][2]) + 1;
                break;
            case 1:
                dp[i + 1][0] = dp[i + 1][2] = -1;
                dp[i + 1][3] = dp[i][0] + 1;
                break;
            case 2:
                dp[i + 1][0] = dp[i + 1][1] = -1;
                dp[i + 1][3] = dp[i][0] + 1;
                break;
            case 3:
                dp[i + 1][0] = dp[i + 1][1] = dp[i + 1][2] = -1;
                break;
        }
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2], dp[n][3]}) << endl;
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