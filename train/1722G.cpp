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
    iota(a.begin(), a.end(), 4);
    int m = n / 4 * 4;
    int d = n - m;
    if (d == 1) {
        a[m] = 0;
    } else if (d == 3) {
        a[m] = 1;
        a[m + 1] = 2;
        a[m + 2] = 3;
    } else if (d == 2) {
        a[0] = (1 << 25);
        a[m] = (1 << 25) + 4;
        a[m + 1] = 0;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
    int r = reduce(a.begin(), a.end(), 0, bit_xor<int>());
    debug(m);
    debug(a);
    assert(r == 0);
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