#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif
// a^2 + b^2 = c^2
// a^2 - b = c
// b^2 + b = c^2 - c
// b + c = c^2 - b^2
// b + c = (c + b)(c - b)
// 1 = c - b

void solve() {
    int n;
    cin >> n;
    int x = n + n - 1;
    int sq = sqrt(x);
    cout << (sq - 1) / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}