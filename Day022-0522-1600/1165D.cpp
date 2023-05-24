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
    vector<i64> a(n);
    for (auto& x : a) cin >> x;

    sort(a.begin(), a.end());
    i64 res = a[0] * a.back();
    if (n & 1)
        res = a[n / 2] * a[n / 2];

    vector<i64> d;
    for (i64 i = 2; i * i <= res; i++) {
        if (res % i == 0) {
            d.push_back(i);
            if (i * i != res) d.push_back(res / i);
        }
    }
    sort(d.begin(), d.end());
    if (d == a) {
        cout << res << '\n';
    } else {
        cout << -1 << '\n';
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