#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int cur = 0;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= q) {
            cur++;
            if (cur >= k) {
                ans += cur - k + 1;
            }
        } else {
            cur = 0;
        }
    }
    cout << ans << endl;
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