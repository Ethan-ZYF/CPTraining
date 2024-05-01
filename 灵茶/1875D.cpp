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
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= n)
            cnt[x]++;
    }
    debug(cnt);
    int mex = 0;
    while (cnt[mex])
        mex++;

    vector<int> dp(mex);
    int ans = mex * (cnt[0] - 1);
    for (int i = 1; i < mex; i++) {
        dp[i] = n * n;
        for (int j = 0; j < i; j++)
            dp[i] = min(dp[i], dp[j] + i * cnt[j]);
        debug(dp);
        ans = min(ans, dp[i] + mex * (cnt[i] - 1));
    }
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