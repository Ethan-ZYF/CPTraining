#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for (auto& x : a) cin >> x;

    auto check = [&](i64 mask) -> bool {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                if (dp[i][j] == 0) continue;
                i64 cur = 0;
                for (int l = i; l < n; l++) {
                    cur += a[l];
                    if ((cur & mask) == mask) {
                        dp[l + 1][j + 1] = 1;
                    }
                }
            }
        }
        return dp[n][k];
    };

    i64 ans = 0;
    for (int base = 60; base >= 0; base--) {
        if (check(ans | (1LL << base))) {
            ans |= (1LL << base);
        }
    }
    cout << ans << "\n";
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