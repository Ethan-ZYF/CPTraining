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
    bitset<100001> dp;
    dp[0] = true;
    for (auto x : a) {
        dp |= dp << x;
    }
    cout << dp.count() - 1 << '\n';
    for (int i = 1; i <= 100000; i++) {
        if (dp[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';
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