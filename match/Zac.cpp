#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, vol;
    cin >> n >> vol;
    vector<int> w(n), p(n), l(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> w[i] >> l[i];
    }

    vector<int> dp(vol + 1);
    for (int i = 0; i < n; i++) {
        int res = l[i];
        for (int k = 1; k <= res; res -= k, k *= 2)
            for (int j = vol; j >= w[i] * k; j--)
                dp[j] = max(dp[j], dp[j - w[i] * k] + p[i] * k);

        for (int j = vol; j >= w[i] * res; j--)
            dp[j] = max(dp[j], dp[j - w[i] * res] + p[i] * res);
    }

    cout << dp[vol] << endl;
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