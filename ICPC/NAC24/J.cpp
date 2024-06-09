#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    long double n, p;
    cin >> n >> p;
    long double sum = 0;
    int ans = n;
    for (int i = 1; i <= n; i++) {
        long double x;
        cin >> x;
        if (sum + (x - 1) * i >= p) {
            ans = min(ans, i - 1);
        }
        sum += x;
    }
    cout << ans << '\n';
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