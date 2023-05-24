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
    vector<i64> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    i64 res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i] * b[i];
    }
    debug(res);
    i64 tmp = 0;
    for (int c = 0; c < n - 1; c++) {
        int left = c, right = n - c - 1;
        i64 mx = 0;
        i64 added = a[c] * b[c];
        i64 minus = a[c] * b[c];
        mx = max(mx, added - minus);
        for (int i = 1; i <= min(left, right); i++) {
            added += a[c - i] * b[c + i];
            added += a[c + i] * b[c - i];
            minus += a[c - i] * b[c - i];
            minus += a[c + i] * b[c + i];
            mx = max(mx, added - minus);
        }
        tmp = max(tmp, mx);
        debug(c, mx, added, minus);
        added = a[c] * b[c + 1] + a[c + 1] * b[c];
        minus = a[c] * b[c] + a[c + 1] * b[c + 1];
        mx = max(mx, added - minus);
        for (int i = 1; i <= min(left, right - 1); i++) {
            added += a[c - i] * b[c + i + 1];
            added += a[c + i + 1] * b[c - i];
            minus += a[c - i] * b[c - i];
            minus += a[c + i + 1] * b[c + i + 1];
            mx = max(mx, added - minus);
        }
        tmp = max(tmp, mx);
        debug(c, mx, added, minus);
    }
    cout << res + tmp << '\n';
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