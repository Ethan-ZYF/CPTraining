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
    for (auto& x : a) cin >> x;

    i64 ans = 0;
    i64 m = 0;
    bool f = false;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i]);
        if (a[i] < 0) {
            if (f) continue;
            f = true;
            m++;
        } else if (a[i] > 0) {
            f = false;
        }
    }
    cout << ans << ' ' << m << endl;
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