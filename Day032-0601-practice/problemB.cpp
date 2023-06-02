#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, x, m;
    cin >> n >> x >> m;
    int l = x, r = x;
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a <= r && b >= l) {
            l = min(l, a);
            r = max(r, b);
        }
    }
    cout << r - l + 1 << "\n";
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