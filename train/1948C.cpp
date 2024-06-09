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
    vector<string> v(2);
    cin >> n >> v[0] >> v[1];
    vector<vector<int>> dp(2, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int j = 0; j < n; j++) {
        if ((dp[1][j] or (j and dp[0][j - 1])) and v[0][j] == '>' and j < n) dp[0][j + 1] = 1;
        if ((dp[0][j] or (j and dp[1][j - 1])) and v[1][j] == '>' and j < n) dp[1][j + 1] = 1;
    }
    cout << (dp[1][n - 1] ? "YES" : "NO") << '\n';
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