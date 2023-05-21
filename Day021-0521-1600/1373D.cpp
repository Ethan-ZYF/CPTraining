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

    vector<array<i64, 3>> dp(n + 2);
    for (int i = 0; i < n; i++) {
        i64 mx = 0;
        for (int j = 0; j < 3; j++) {
            mx = max(mx, dp[i][j]);
            switch (j) {
                case 0:
                    dp[i + 1][j] = mx + (i % 2 == 0 ? a[i] : 0);
                    break;
                case 1:
                    dp[i + 2][j] = mx + (i % 2 == 0 ? a[i + 1] : a[i]);
                    break;
                case 2:
                    dp[i + 1][j] = mx + (i % 2 == 0 ? a[i] : 0);
                    break;
            }
        }
    }
    cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
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