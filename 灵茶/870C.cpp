#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, ans = 0;
    cin >> n;
    if (n & 1) {
        n -= 9;
        ans = 1;
    }
    if (n == 0) {
        cout << ans << '\n';
        return;
    }
    if (n < 4) {
        cout << -1 << '\n';
        return;
    }
    ans += n / 4;
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