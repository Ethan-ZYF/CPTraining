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

    if (n <= 2) {
        cout << n << "\n";
    } else if (n % 2) {
        cout << 1LL * n * (n - 1) * (n - 2) << "\n";
    } else if (n % 3) {
        cout << 1LL * n * (n - 1) * (n - 3) << "\n";
    } else {
        cout << 1LL * (n - 1) * (n - 2) * (n - 3) << "\n";
    }
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