#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 0) {
        cout << 1 << "\n";
    } else {
        cout << a + min(b, c) * 2 + min(a + 1, abs(b - c) + d) << "\n";
    }
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