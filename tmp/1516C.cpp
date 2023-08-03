#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

int low_bit(int x){
    return x & (-x);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    i64 sum = accumulate(a.begin(), a.end(), 0LL);
    if (sum % 2 == 1) {
        cout << 0 << endl;
        return;
    }
    debug(sum);
    sum /= 2;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= 0; j--) {
            dp[i + 1][j] |= dp[i][j];
            if (j >= a[i]) dp[i + 1][j] |= dp[i][j - a[i]];
        }
    }
    if (!dp[n][sum]) {
        cout << 0 << endl;
        return;
    }
    cout << 1 << endl;
    for_each(a.begin(), a.end(), [](int& x) { x = low_bit(x); });
    cout << min_element(a.begin(), a.end()) - a.begin() + 1 << endl;
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