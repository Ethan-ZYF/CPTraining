#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    array<i64, 3> a;
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    i64 ans = accumulate(a.begin(), a.end(), 0LL) / 3;
    ans = min(ans, a[0] + a[1]);
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