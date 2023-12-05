#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto& it : a) cin >> it;
    for (auto& it : b) cin >> it;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    debug(a);
    debug(b);
    i64 sum1 = accumulate(a.begin(), a.end(), 0LL);
    debug(sum1);
    if (k % 2 == 1) {
        i64 sum2 = sum1 - a[0] + b.back();
        cout << max(sum1, sum2) << endl;
    } else {
        i64 sum2 = sum1 - a[0] + b.back();
        sum2 = max(sum2, sum1);
        i64 sum3 = sum2 + min(a[0], b[0]) - max(a.back(), b.back());
        cout << sum3 << endl;
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