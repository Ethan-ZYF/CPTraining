#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr int MOD = 2147483648;

void solve() {
    int n;
    cin >> n;
    vector<i64> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n - 1; i++)
        for (int j = i; j <= n; j++)
            f[j] = (f[j] + f[j - i]) % MOD;
    cout << f[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}