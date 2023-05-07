#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int p = 0;
    vector<int> lo(m), hi(m);
    for (int i = 0; i < m; i++) {
        while (s[p] != t[i]) p++;
        lo[i] = p;
        p++;
    }
    p = n - 1;
    for (int i = m - 1; i >= 0; i--) {
        while (s[p] != t[i]) --p;
        hi[i] = p;
        --p;
    }
    debug(lo, hi);
    int ans = 0;
    for (int i = 0; i < m - 1; i++) {
        ans = max(ans, hi[i + 1] - lo[i]);
    }
    cout << ans << '\n';
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