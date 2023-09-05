#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    i64 n, x, y;
    cin >> n >> x >> y;
    vector<i64> a(n);
    for (auto& x : a) cin >> x;
    i64 res = reduce(a.begin(), a.end(), x, bit_xor<i64>());
    if ((res - y) % 2 == 0) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
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