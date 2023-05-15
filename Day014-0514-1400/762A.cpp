#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif


void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64> d;
    for (i64 i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (i * i != n) {
                d.push_back(n / i);
            }
        }
    }
    sort(d.begin(), d.end());
    if (k > d.size()) {
        cout << -1 << '\n';
        return;
    }
    cout << d[k - 1] << '\n';
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