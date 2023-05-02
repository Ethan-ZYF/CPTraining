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
    vector<int> a(n + 1), dp(n + 1, 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        for (int j = i + i; j <= n; j += i) {
            if (a[i] < a[j]) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }
    // debug(dp);
    cout << *max_element(dp.begin(), dp.end()) << '\n';
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